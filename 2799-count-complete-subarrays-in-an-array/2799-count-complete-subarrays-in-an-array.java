class Solution {
    public int countCompleteSubarrays(int[] nums) {
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }

        int k = set.size();

        HashMap<Integer, Integer> map = new HashMap<>();
        int total = 0;
        int prefix = 0;
        int left = 0;

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);

            while (map.size() == k) {
                map.put(nums[left], map.getOrDefault(nums[left], 0) - 1);
                if (map.get(nums[left]) == 0) map.remove(nums[left]);
                left++;
            }

            total += left;
        }

        return total;
    }
}