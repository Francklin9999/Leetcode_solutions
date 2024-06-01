class Solution {
    int[] memo;
    public int minCostClimbingStairs(int[] cost) {
        memo = new int[cost.length];
        Arrays.fill(memo, -1);
        return Math.min(helper(cost, cost.length - 1), helper(cost, cost.length - 2));
    }

    private int helper(int[] cost, int i) {
        if (i < 0) return 0;
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = cost[i] + Math.min(helper(cost, i - 1), helper(cost, i - 2));
        return memo[i];
    }
}