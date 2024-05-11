class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length == 1) return true;
        
        int r = nums.length - 1;
        int l = nums.length - 2;

        while (l >= 0) {
            if ((r - l) - nums[l] <= 0) {
                r = l;
                if (r == 0) return true;
                l--;
            } else {
                l--;
            }
        }
        return false;
    }
}