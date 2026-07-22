class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int prefix = 0;
        int total = 0;
        map.put(0, 1);

        for (int i = 0; i < nums.length; i++) {
            prefix += nums[i];

            total += map.getOrDefault(prefix - k, 0);

            map.put(prefix, map.getOrDefault(prefix, 0) + 1);
        }

        return total;
    }
}