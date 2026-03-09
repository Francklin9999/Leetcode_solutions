class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0;
        int r = 1;
        while (r < prices.size()) {
            profit = std::max(profit, prices[r] - prices[l]);
            if (prices[r] < prices[l]) l = r;
            r++;
        }

        return profit;
    }
};