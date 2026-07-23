class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        int total = 0;
        int prefix = 0;
        for (int r = 0; r < nums.length; r++) {
            prefix += nums[r];

            total += map.getOrDefault(prefix - goal, 0);

            map.put(prefix, map.getOrDefault(prefix, 0) + 1);
        }

        return total;
    }
}