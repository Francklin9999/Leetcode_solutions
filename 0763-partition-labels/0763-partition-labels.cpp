class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> vec(26, pair<int, int>(-1, -1));
        vector<int> res;

        for (auto i = 0uz; i < s.size(); ++i) {
            if (vec[s.at(i) - 'a'].first == -1) {
                vec[s.at(i) - 'a'].first = i;
                vec[s.at(i) - 'a'].second = i;
            } else {
                vec[s.at(i) - 'a'].second = i;
            }
        }

        int currMin{-1};
        int currMax{vec[s.at(0) - 'a'].second};

        for (auto i = 0uz; i < s.size(); ++i) {
            currMax = std::max(currMax, vec[s.at(i) - 'a'].second);

            if (currMax == i) {
                res.push_back(currMax - currMin);
                currMin = currMax;
            }
        }

        return res;
    }
};