class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, ArrayList<String>> map = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            char[] chararray = strs[i].toCharArray();
            Arrays.sort(chararray);
            String word = new String(chararray);
            if (!map.containsKey(word)) {
                map.put(word, new ArrayList<String>());
            } 
            map.get(word).add(strs[i]);
        }
        return new ArrayList<>(map.values());
    }
}