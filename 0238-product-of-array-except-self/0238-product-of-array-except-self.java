class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] before = new int[nums.length];
        int[] result = new int[nums.length];
        before[0] = 1;
        for(int i = 1; i < nums.length; i++) {
            before[i] = nums[i - 1] * before[i - 1];
        }

        result[nums.length - 1] = before[nums.length - 1];
        for(int j = nums.length - 2; j >= 0; j--) {
            result[j] = before[j] * nums[j + 1];
            nums[j] *= nums[ j + 1];
        }

        return result;
    }
}