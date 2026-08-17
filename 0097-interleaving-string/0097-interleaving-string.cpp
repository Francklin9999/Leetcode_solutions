class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[s1.size()][s2.size()] = true;

        for (auto i{dp.size()}; i-- > 0; ) {
            for (auto j{dp[0].size()}; j-- > 0; ) {
                if (i < s1.size() && s1[i] == s3[i + j] && dp[i + 1][j]) dp[i][j] = true;
                if (j < s2.size() && s2[j] == s3[i + j] && dp[i][j + 1]) dp[i][j] = true;
            }
        }

        return dp[0][0];
    }
};