class Solution {
    public boolean isPalindrome(String s) {
        String newS = s.toLowerCase();
        int l = 0;
        int r = s.length() - 1;

        while(l < r) {
            while(l < r && !Character.isLetterOrDigit(newS.charAt(l))) l++;
            while(l < r && !Character.isLetterOrDigit(newS.charAt(r))) r--;
    
            if(newS.charAt(l) != newS.charAt(r)) return false;

            l++;
            r--;
        }

        return true;
    }
}