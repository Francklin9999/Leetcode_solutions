class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if (numbers.length == 0) return new int[0];
        int i = 0;
        int j = numbers.length - 1;
        int sum;
        while (i <= j) {
            sum = numbers[i] + numbers[j];
            if (sum == target) return new int[] {i + 1, j + 1};
            if (sum < target) {
                i++;
                continue;
            }
            if (sum > target) {
                j--;
                continue;
            }
        }
    return new int[0];
    }
}