class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> set;

        for (int i{}; i < n / 2 + 1; ++i) {
            set.insert(i * i);
        }

        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i{}; i <= n; ++i) {
            for (auto& val : set) {
                if (i >= val) {
                    dp[i] = std::min(dp[i], dp[i - val] + 1);
                }
            }
        }

        return dp[n];
    }
};