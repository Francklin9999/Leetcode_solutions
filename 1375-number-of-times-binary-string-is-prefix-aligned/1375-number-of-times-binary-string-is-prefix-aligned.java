class Solution {
    public int numTimesAllBlue(int[] flips) {
        HashSet<Integer> set = new HashSet<>();

        int looking = 1;
        int total = 0;

        for (int i = 0; i < flips.length; i++) {
            set.add(flips[i]);
            if (flips[i] == looking) {
                while(looking != i + 1 && set.contains(looking)) looking++;
                if (looking == i + 1 && set.contains(looking)) {
                    total++;
                    looking++;
                }
            }
        }

        return total;
    }
}