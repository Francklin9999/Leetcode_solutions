class Solution {
int helper(vector<int>& nums, vector<vector<int>>& dp, int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != INT_MIN) return dp[l][r];

    dp[l][r] = std::max(
        nums[l] - helper(nums, dp, l + 1, r),
        nums[r] - helper(nums, dp, l, r - 1)
    );

    return dp[l][r];
}
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), INT_MIN));

        return helper(nums, dp, 0, nums.size() - 1) >= 0;
    }
};