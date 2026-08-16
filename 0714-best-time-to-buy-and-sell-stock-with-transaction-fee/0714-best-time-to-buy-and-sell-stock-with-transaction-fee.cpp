class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy{-prices[0] - fee}, sell{};

        for (auto i{1uz}; i < prices.size(); ++i) {
            buy = std::max(buy, sell - prices[i] - fee);
            sell = std::max(sell, buy + prices[i]);
        }

        return sell;
    }
};