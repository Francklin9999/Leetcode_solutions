class Solution {
    public int findPermutationDifference(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();
        int permutation = 0;
        int length = s.length();

        for (int i = 0; i < length; i++) {
            map.put(s.charAt(i), i);
        }

        for (int j = 0; j < length; j++) {
            permutation += Math.abs(map.get(t.charAt(j)) - j);
        }
        return permutation;
    }
}