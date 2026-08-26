class Solution {
pair<int, int> helper(vector<int>& piles, vector<vector<pair<int, int>>>& dp, int l, int m) {
    if (l >= piles.size()) return make_pair(0, 0);
    if (dp[l][m].first != INT_MIN && dp[l][m].second != INT_MIN) return dp[l][m];

    int sum{};

    for (int i = l; i < (2 * m + l); ++i) {
        if (i >= piles.size()) break;
        sum += piles[i];

        auto left = helper(piles, dp, i + 1, std::max(m, i - l + 1));

        auto take = pair<int, int>(
            sum + left.second,
            left.first
        );

        if (dp[l][m].first <= take.first) {
            dp[l][m] = take;
        }
    }

    return dp[l][m];
}

public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<pair<int, int>>> dp(piles.size(), vector<pair<int, int>>(piles.size() + 1, {INT_MIN, INT_MIN}));
        return helper(piles, dp, 0, 1).first;
    }
};