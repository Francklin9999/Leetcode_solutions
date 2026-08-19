class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        vector<int> run_sum(possible.size());

        for (auto i{0uz}; i < possible.size(); ++i) {
            if (possible[i] == 0) run_sum[i] = -1;
            else run_sum[i] = 1;
            
            if (i > 0) run_sum[i] += run_sum[i - 1];
        }

        auto max = run_sum[run_sum.size() - 1];

        for (auto i{0uz}; i < possible.size() - 1; ++i) {
            if (run_sum[i] > (max / 2.0)) return i + 1;
        }

        return -1;
    }
};