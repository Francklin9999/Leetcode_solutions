class Solution {
    public int climbStairs(int n) {
        int[] memo = new int[2];
        memo[0] = 0;
        memo[1] = 1;
        int temp;
        for (int i = 1; i <= n; i++) {
            temp = memo[0] + memo[1];
            memo[0] = memo[1];
            memo[1] = temp;
        }
        return memo[1];
    }
}