class Solution {
int helper(vector<int>& piles, vector<vector<int>>& dp, int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != INT_MIN) return dp[l][r];

    dp[l][r] = std::max(
        piles[l] - helper(piles, dp, l + 1, r),
        piles[r] - helper(piles, dp, l, r - 1)
    );

    return dp[l][r];
}
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), INT_MIN));

        return helper(piles, dp, 0, piles.size() - 1) > 0;
    }
};