class Solution {
    public int appendCharacters(String s, String t) {
        int sLength = s.length();
        int tLength = t.length();

        int l = 0;
        int r = 0;

        while(l < sLength && r < tLength) {
            if(s.charAt(l) == t.charAt(r)) {
                l++;
                r++;
            } else {
                l++;
            }
        }

        return tLength - r;
    }
}