class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) return 0;

        Set<Integer> set = new HashSet<>();
        int sequence = 0;
        int maxsequence = 0;

        for(int num : nums) set.add(num);

        for(int value : nums) {
            if(set.contains(value - 1)) continue;
            sequence = 1;
            while(set.contains(value + 1)) {
                sequence++;
                set.remove(value);
                value++;
            }
            maxsequence = Math.max(maxsequence, sequence);
        }

        return maxsequence;
    }
}