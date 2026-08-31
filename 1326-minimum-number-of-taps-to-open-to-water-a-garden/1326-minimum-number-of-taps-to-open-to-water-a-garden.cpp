class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int m = ranges.size();
        vector<int> dp(n + 1, 0);

        for (int i{0}; i < m; ++i) {
            auto left = std::max(0, i - ranges[i]);
            auto right = std::min(m - 1, ranges[i] + i);
            dp[left] = std::max(dp[left], right);
        }

        int l{0}, end{0}, farthest{0}, taps{0};

        while (end < n) {
            while (l <= end) {
                farthest = std::max(dp[l++], farthest);
            }

            if (farthest <= end) return -1;

            end = farthest;
            ++taps;
        }

        return taps;
    }
};