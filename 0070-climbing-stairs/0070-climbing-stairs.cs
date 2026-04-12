public class Solution {
    public int ClimbStairs(int n) {
        int prev1 = 1;
        int prev2 = 0;
        int x = 0;

        for (int i = 0; i < n; i++) {
            x = prev1 + prev2;
            prev2 = prev1;
            prev1 = x;
        }

        return x;
    }
}