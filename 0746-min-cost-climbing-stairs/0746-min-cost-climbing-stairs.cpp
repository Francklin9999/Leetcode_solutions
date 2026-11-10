class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1{0}, prev2{0};

        for (auto i{0uz}; i < cost.size(); ++i) {
            int tmp = prev1;
            prev1 = std::min(prev1, prev2) + cost[i];
            prev2 = tmp;
        }

        return std::min(prev1, prev2);
    }
};