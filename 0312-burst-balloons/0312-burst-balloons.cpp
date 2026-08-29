class Solution {
int helper(vector<int>& nums, vector<vector<int>>& dp, int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != INT_MIN) return dp[l][r];

    for (auto i{l}; i <= r; ++i) {
        auto curr = nums[l - 1] * nums[i] * nums[r + 1];

        dp[l][r] = std::max(
            dp[l][r],
            helper(nums, dp, l, i - 1) +
            helper(nums, dp, i + 1, r) +
            curr
        );
    }

    return dp[l][r];
}
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));

        return helper(nums, dp, 1, n);
    }
};