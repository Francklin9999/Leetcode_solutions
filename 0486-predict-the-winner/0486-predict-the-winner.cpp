class Solution {
int helper(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int takeL = nums[l] - helper(
        nums,
        l + 1,
        r,
        dp
    );

    int takeR = nums[r] - helper(
        nums,
        l,
        r - 1,
        dp
    );

    return dp[l][r] = std::max(takeL, takeR);
}
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return helper(nums, 0, nums.size() - 1, dp) >= 0; 
    }
};