class Solution {
    public int search(int[] nums, int target) {
        int i = 0, j = nums.length - 1, middle;
        while( i <= j) {
            middle = i + (j - i) / 2;
            if (nums[middle] > target) j = middle - 1;
            else if (nums[middle] < target) i = middle + 1;
            else if (nums[middle] == target) return middle;
        }
    return -1;
    }
}
