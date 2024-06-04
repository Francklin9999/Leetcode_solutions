class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[58];
        int length = s.length();
        int result = 0;

        for(int i = 0; i < length; i++) {
            count[s.charAt(i) - 'A']++;
        }

        for(int j = 0; j < count.length; j++) {
            if(count[j] % 2 == 0) result += count[j];
            else result += count[j] - count[j] % 2;
        }

        if(result < length) result++;

        return result;
    }
}