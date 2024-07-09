class Solution {
    public int search(int[] nums, int target) {
        int r = nums.length - 1;
        int l = 0;
        int mid = 0;

        while(l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
}