class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min{prices[0]}, max{0};

        for (auto i{1uz}; i < prices.size(); ++i) {
            max = std::max(prices[i] - min, max);
            min = std::min(min, prices[i]);
        }

        return max;
    }
};