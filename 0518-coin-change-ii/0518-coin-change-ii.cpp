class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (auto i{coin}; i < dp.size(); ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};