class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy{-prices[0]}, sell{}, cooldown{};

        for (auto i{1uz}; i < prices.size(); ++i) {
            auto t_buy = buy;
            auto t_sell = sell;

            buy = std::max(buy, cooldown - prices[i]);
            sell = std::max(sell, t_buy + prices[i]);
            cooldown = t_sell;
        }
        
        return std::max(sell, cooldown);
    }
};