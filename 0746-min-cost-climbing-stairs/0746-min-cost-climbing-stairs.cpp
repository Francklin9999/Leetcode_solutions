class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int last1 = 0;
        int last2 = 0;

        for (int i = 0; i < cost.size(); ++i) {
            int temp = cost[i] + std::min(last1, last2);
            last1 = last2;
            last2 = temp;
        }

        return std::min(last1, last2);
    }
};