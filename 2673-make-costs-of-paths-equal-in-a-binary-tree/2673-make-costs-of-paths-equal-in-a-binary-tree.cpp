class Solution {
private:
    int increments(vector<int>& cost, int low, int high, int& total) {
        if (2 * low > high) return cost[low - 1];

        auto left = increments(cost, 2 * low, high, total);
        auto right = increments(cost, 2 * low + 1, high, total);

        auto diff = std::abs(left - right);
        
        total += diff;

        return cost[low - 1] + std::max(left, right);
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        int total{};
        increments(cost, 1, n, total);
        return total;
    }
};