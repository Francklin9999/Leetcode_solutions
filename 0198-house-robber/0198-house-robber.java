class Solution {
    int[] memo;
    public int rob(int[] nums) {
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return Math.max(helper(nums, 0), helper(nums, 1));
    }

    private int helper(int[] nums, int i) {
        if (i > nums.length - 1) return 0;
        if (memo[i] != -1) return memo[i];

        memo[i] = nums[i] + Math.max(helper(nums, i + 2), helper(nums, i + 3));
        return memo[i];
    }
}