class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));

        for (auto i = 0uz; i < text1.size(); ++i) {
            for (auto j = 0uz; j < text2.size(); ++j) {
                dp[i][j] = 0;
                if (text1[i] == text2[j]) {
                    dp[i][j]++;
                    if ((i > 0) && (j > 0)) {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                } else {
                    int cand1{};
                    int cand2{};
                    if (i > 0) {
                        cand1 = dp[i - 1][j];
                    }
                    if (j > 0) {
                        cand2 = dp[i][j - 1];
                    }
                    dp[i][j] = std::max(cand1, cand2);
                }
            }
        }

        return dp[text1.size() - 1][text2.size() - 1];
    }
};