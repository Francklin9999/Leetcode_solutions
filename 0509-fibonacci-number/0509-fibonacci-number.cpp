class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int prev1{1}, prev2{0};
        
        for (int i = 2; i <= n; ++i) {
            auto tmp = prev1;
            prev1 = prev1 + prev2;
            prev2 = tmp;
        }

        return prev1;
    }
};