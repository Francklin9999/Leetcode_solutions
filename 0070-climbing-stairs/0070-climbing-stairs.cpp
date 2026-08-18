class Solution {
public:
    int climbStairs(int n) {
        int prev1{}, prev2{1};

        for (auto i{0}; i <= n; ++i) {
            auto tmp = prev1;
            prev1 = prev1 + prev2;
            prev2 = tmp;
        }

        return prev1;
    }
};