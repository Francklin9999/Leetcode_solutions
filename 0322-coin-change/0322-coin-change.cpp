class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i{0}; i <= amount; ++i) {
            for (int coin : coins) {
                auto res = i - coin;
                if (res >= 0) {
                    dp[i] = std::min(dp[i], dp[res] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};