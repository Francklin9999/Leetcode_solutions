class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res{0};
        int buy{prices[0]}, sell{};

        for (auto i{1uz}; i < prices.size(); ++i) {
            sell = prices[i] - buy;
            buy = std::min(buy, prices[i]);
            res = std::max(res, sell);
        }

        return res;
    }
};