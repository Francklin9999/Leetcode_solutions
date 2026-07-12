class Solution {
public:
    int climbStairs(int n) {
        int prev1{1}, prev2{0};

        for (int i{}; i < n; ++i) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};