class Solution {
int helper(vector<int>& nums, vector<int>& multipliers, map<pair<int, int>, int>& dp, int l, int r, int idx) {
    if (idx == multipliers.size()) return 0;
    if (dp.count({l, r})) return dp[{l, r}];

    return dp[{l, r}] = std::max(
        helper(nums, multipliers, dp, l + 1, r, idx + 1) + nums[l] * multipliers[idx],
        helper(nums, multipliers, dp, l, r - 1, idx + 1) + nums[r] * multipliers[idx]
    );
}
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, INT_MIN));
        map<pair<int, int>, int> dp;

        return helper(nums, multipliers, dp, 0, nums.size() - 1, 0);
    }
};