class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy{-prices[0]}, sell{};

        for (auto i{1uz}; i < prices.size(); ++i) {
            auto t_buy = buy;
            auto t_sell = sell;

            buy = std::max(t_sell - prices[i], t_buy); 
            sell = std::max(t_sell, t_buy + prices[i]);
        }

        return sell > 0 ? sell : 0;
    }
};