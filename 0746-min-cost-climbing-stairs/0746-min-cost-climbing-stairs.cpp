class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1{}, prev2{};

        for (auto i{0uz}; i < cost.size(); ++i) {
            auto tmp = prev1;
            prev1 = std::min(prev1, prev2) + cost[i];
            prev2 = tmp;
        }

        return std::min(prev1, prev2);
    }
};