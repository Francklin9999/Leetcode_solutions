class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best{}, buy{INT_MAX};

        for (auto i{0uz}; i < prices.size(); ++i) {
            buy = std::min(buy, prices[i]);
            best = std::max(best, prices[i] - buy);
        }

        return best;
    }
};