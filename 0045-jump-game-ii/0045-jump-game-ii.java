class Solution {
    public int jump(int[] nums) {
        if (nums.length == 1) return 0;
        int l = 1;
        int r = nums[0];
        int count = 1;

        while (r < nums.length - 1) {
            count++;
            while (l < r) {
                if (nums[l] + l < nums[r] + r) {
                    l++;
                } else {
                    r--;
                }
            }
            r = l + nums[l];
            l = l + 1;
        }
        return count;
    }
}