class Solution {
int helper(int l, int r, vector<vector<int>>& dp) {
    if (l >= r) return 0;
    if (dp[l][r] != INT_MAX) return dp[l][r];

    for (int i{l}; i <= r; ++i) {
        dp[l][r] = std::min(
            dp[l][r],
            std::max(
                helper(l, i - 1, dp),
                helper(i + 1, r, dp)
            ) + i
        );
    }

    return dp[l][r];
}
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        return helper(1, n, dp);
    }
};