class Solution {
pair<int, int> helper(vector<int>& stoneValue, vector<pair<int, int>>& dp, int l) {
    if (l >= stoneValue.size()) return make_pair(0, 0);
    if (dp[l].first != INT_MIN) return dp[l];

    int sum{};

    for (int i{l}; i < l + 3; ++i) {
        if (i >= stoneValue.size()) break;

        sum += stoneValue[i];

        auto next = helper(stoneValue, dp, i + 1);
        auto take = pair<int, int>(
            sum + next.second,
            next.first
        );

        if (dp[l].first < take.first) {
            dp[l] = take;
        }
    }

    return dp[l];
}

public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<pair<int, int>> dp(stoneValue.size(), {INT_MIN, INT_MIN});

        auto res = helper(stoneValue, dp, 0);

        if (res.first > res.second) return "Alice";
        if (res.second > res.first) return "Bob";
        return "Tie";        
    }
};