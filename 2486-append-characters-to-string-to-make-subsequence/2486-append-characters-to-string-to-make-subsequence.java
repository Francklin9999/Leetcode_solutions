class Solution {
    public int appendCharacters(String s, String t) {
        int length1 = s.length();
        int length2 = t.length();

        int l = 0;
        int r = 0;

        while(l < length1 && r < length2) {
            if(s.charAt(l) == t.charAt(r)) {
                l++;
                r++;
            } else {
                l++;
            }
        }

        return length2 - r;
    }
}