class Solution {
    public String reversePrefix(String word, char ch) {
        Stack<Character> stack = new Stack<>();
        String newWord = "";
        int index = 0;
        if (!word.contains(String.valueOf(ch))) return word;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                index = i + 1;
                newWord += word.charAt(i);
                break;
            }
            stack.push(word.charAt(i));
        }
        while (!stack.isEmpty()) {
            newWord += stack.pop();
        }
        while (index < word.length()) {
            newWord += word.charAt(index);
            index++;
        }
        return newWord;
    }
}