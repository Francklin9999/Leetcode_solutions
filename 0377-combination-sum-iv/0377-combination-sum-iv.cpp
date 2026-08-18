class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; ++i) {
            for (int num : nums) {
                auto res = i - num;
                if (res >= 0) {
                    dp[i] += dp[res];
                }
            }
        }

        return dp[target];
    }
};