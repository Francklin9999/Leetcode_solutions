class Solution {
    public int strStr(String haystack, String needle) {
        int l = 0;
        int r = 0;
        int length1 = haystack.length();
        int length2 = needle.length();

        if(length2 > length1) return -1;

        for(int i = 0; i < length1; i++) {
            if(haystack.charAt(i) == needle.charAt(r)) {
                l = i + 1;
                r++;
                while(r < length2 && l < length1 && haystack.charAt(l) == needle.charAt(r)){
                    r++;
                    l++;
                }
                if(r == length2) return i;
                r = 0;
            }
        }

        return -1;
    }
}