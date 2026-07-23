class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int[] clone = nums.clone();
        Arrays.sort(clone);

        HashMap<Integer, Integer> map = new HashMap<>();

        int k2 = k;
        int n = clone.length - 1;
        while (k2 > 0) {
            map.put(clone[n], map.getOrDefault(clone[n], 0) + 1);
            n--;
            k2--;
        }

        int[] res = new int[k];

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                res[k2++] = nums[i];
                map.put(nums[i], map.getOrDefault(nums[i], 0) - 1);
                if (map.get(nums[i]) <= 0) map.remove(nums[i]);
            }
        }

        return res;
    }
}