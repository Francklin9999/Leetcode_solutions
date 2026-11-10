class Solution {
public:
    int climbStairs(int n) {
        int prev1{1}, prev2{};

        for (auto i{0uz}; i < n; ++i) {
            int tmp = prev1;
            prev1 = prev1 + prev2;
            prev2 = tmp;
        }

        return prev1;
    }
};