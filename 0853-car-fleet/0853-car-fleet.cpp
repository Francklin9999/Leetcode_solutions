class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> vec;

        for (auto i{0uz}; i < position.size(); ++i) {
            vec.push_back(pair<int, double>(position[i],
                (target - position[i]) / static_cast<double>(speed[i])
            ));
        }

        sort(vec.begin(), vec.end());

        int fleet{1};
        auto curr_max{vec[vec.size() - 1].second};

        for (auto i{vec.size() - 1}; i-- > 0; ) {
            if (vec[i].second > curr_max) {
                ++fleet;
                curr_max = vec[i].second;
            }
        }

        return fleet;
    }
};