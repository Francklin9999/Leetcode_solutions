class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy{-prices[0]}, sell{}, cooldown{};

        for (auto i{1uz}; i < prices.size(); ++i) {
            auto t_buy = buy;
            auto t_sell = sell;
            auto t_cooldown = cooldown;

            buy = std::max(t_buy, t_cooldown - prices[i]);
            sell = prices[i] + t_buy;
            cooldown = std::max(t_cooldown, t_sell);
        }

        return std::max(sell, cooldown);
    }
};