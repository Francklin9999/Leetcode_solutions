class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m][n - 1] = 1;

        for (auto i{m}; i-- > 0; ) {
            for (auto j{n}; j-- > 0; ) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};