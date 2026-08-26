class Solution {
pair<int, int> helper(vector<int>& nums, vector<vector<pair<int, int>>>& dp, int l, int r) {
    if (l > r) return make_pair(0, 0);
    if (dp[l][r].first != INT_MIN && dp[l][r].second != INT_MIN) return dp[l][r];

    auto left = helper(nums, dp, l + 1, r);
    auto takeLeft = pair<int, int>(
        nums[l] + left.second,
        left.first
    );
    
    auto right = helper(nums, dp, l, r - 1);
    auto takeRight = pair<int, int>(
        nums[r] + right.second,
        right.first
    );

    if (takeLeft.first >= takeRight.first) {
        dp[l][r] = takeLeft;
    } else {
        dp[l][r] = takeRight;
    }

    return dp[l][r];
}
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<pair<int, int>>> dp(nums.size(), vector<pair<int, int>>(nums.size(), pair<int, int>(INT_MIN, INT_MIN)));

        auto p = helper(nums, dp, 0, nums.size() - 1); 

        return  p.first >= p.second;
    }
};