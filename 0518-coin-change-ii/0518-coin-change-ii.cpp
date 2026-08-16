class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> cache(amount + 1);
        cache[0] = 1;

        for (int coin : coins)  {
            for (int i = coin; i <= amount; ++i) {
                cache[i] += cache[i - coin];
            }
        }

        return cache[amount];
    }
};