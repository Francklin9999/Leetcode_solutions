class Solution {
public:
    string oddString(vector<string>& words) {
        vector<int> w1;
        vector<int> w2;

        for (auto i{0uz}; i < words.size(); ++i) {
            vector<int> curr(words[0].size() - 1);
            for (auto j{0uz}; j < words[i].size() - 1; ++j) {
                curr[j] = words[i][j + 1] - words[i][j];
            }

            if (i == 0) w1 = curr;
            else if (i == 1) w2 = curr;
            else if (w1 != curr) {
                if (curr == w2) return words[0];
                else return words[i];
            }
        }

        return words[1];
    }
};