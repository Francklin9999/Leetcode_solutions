class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1{}, prev2{};

        for (auto i = 0uz; i < cost.size(); ++i) {
            int tmp = prev1;
            prev1 = cost[i] + std::min(prev1, prev2);
            prev2 = tmp;
        }

        return std::min(prev1, prev2);
    }
};