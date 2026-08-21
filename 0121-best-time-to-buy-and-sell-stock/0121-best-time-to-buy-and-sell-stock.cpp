class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy{prices[0]}, profit{};

        for (auto i{1uz}; i < prices.size(); ++i) {
            profit = std::max(profit, prices[i] - buy);
            buy = std::min(buy, prices[i]);
        }

        return profit;
    }
};