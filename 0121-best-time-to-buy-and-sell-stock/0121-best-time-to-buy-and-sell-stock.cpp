class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy{prices[0]};
        int profit{};

        for (auto i{1uz}; i < prices.size(); ++i) {
            buy = std::min(buy, prices[i]);
            profit = std::max(profit, prices[i] - buy);
        }

        return profit;
    }
};