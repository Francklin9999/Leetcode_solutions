class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        ArrayList<String> list = new ArrayList<>();
        list.add("+");
        list.add("-");
        list.add("*");
        list.add("/");
        int x;
        int y;
        int exp;
        // char[] words = tokens.toCharArray();
        for (String i : tokens) {
            if (list.contains(i) && stack.size() > 1) {
                x = stack.pop();
                y = stack.pop();
                switch(i) {
                    case "+":
                        exp = y + x;
                        break;
                    case "-":
                        exp = y - x;
                        break;
                    case "*":
                        exp = y * x;
                        break;
                    case "/":
                        exp = y / x;
                        break;
                    default:
                        exp = 0;
                        break;
                }
                stack.push(exp);
            }
            else {
                stack.push(Integer.parseInt(i));
            }
        }
        return stack.pop();
    }
}