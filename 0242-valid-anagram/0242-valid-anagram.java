class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;

        int[] occurences = new int[26];

        for(int i = 0; i < occurences.length; i++) {
            occurences[i] = 0;
        }

        for(int i = 0; i < s.length(); i++) {
            occurences[s.charAt(i) - 'a'] += 1;
        }

        for(int i = 0; i < t.length(); i++) {
            occurences[t.charAt(i) - 'a'] -= 1;
        }

        int sumArray = 0;
        for(int i = 0; i < occurences.length; i++) {
            if (occurences[i] != 0) return false;
        }

        return true;
    }
}