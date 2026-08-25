class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target + 1, 0);
        dp[0] = 1;

        for (int i{1}; i <= target; ++i) {
            for (auto j{0uz}; j < nums.size(); ++j) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};