class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();

        int res = 0;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            if (set.contains(s.charAt(r))) {
                res = Math.max(res, r - l);
                while (s.charAt(l) != s.charAt(r)) set.remove(s.charAt(l++));
                l++;
            } else {
                set.add(s.charAt(r));
            }
        }

        return Math.max(res, s.length() - l);
    }
}