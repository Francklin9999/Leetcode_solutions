class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto i{nums1.size()}; i-- > 0; ) {
            for (auto j{nums2.size()}; j-- > 0; ) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = std::max(
                        dp[i + 1][j],
                        dp[i][j + 1]
                    );
                }
            }
        }

        return dp[0][0];
    }
};