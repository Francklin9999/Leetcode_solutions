class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        int result = 0;

        int length = s.length();
        for(int i = 0; i < length; i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        for(Map.Entry<Character, Integer> it : map.entrySet()) {
            if(it.getValue() % 2 == 0) result += it.getValue();
            else result += it.getValue() - (it.getValue() % 2);
        }
        
        if(result < length) result++;
    
        return result;
    }
}