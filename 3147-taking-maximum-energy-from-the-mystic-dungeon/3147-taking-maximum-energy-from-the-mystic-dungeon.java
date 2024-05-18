class Solution {

    int max = Integer.MIN_VALUE;
    HashMap<Integer, Integer> map = new HashMap<>();
    public int maximumEnergy(int[] energy, int k) {
        for (int i = 0; i < energy.length; i++) {
            max = Math.max(max, helper(energy, k, i));
        }
        return max;
    }

    private int helper(int[] energy, int k, int i) {
        if (i >= energy.length) return 0;
        if (!map.containsKey(i)) {
            int value = helper(energy,k, i + k);
            map.put(i, value + energy[i]);
            return value + energy[i];
        }
        return map.get(i);
    }
}