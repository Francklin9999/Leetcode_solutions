class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int length = temperatures.length;
        if (length == 0) return new int[0];
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        int counter = 2;
        for (int i = length - 2; i >= 0; i--) {
            if (temperatures[i] >= temperatures[i + 1] && stack.peek() == 0) {
                stack.push(0);
            }  else if (temperatures[i] == temperatures[i + 1]) {
                stack.push(stack.peek() + 1);
            } else if (temperatures[i] > temperatures[i + 1]) {
                int j = i;
                while (temperatures[i] >= temperatures[j + 2]) {
                    counter += 1;
                    j++;
                    if (j + 2 > length - 1) {
                        counter = 0; 
                        break;
                    }
                };
                stack.push(counter);
                counter = 2;
            } else {
                stack.push(1);
            }
        }
        int[] result = new int[length];
        int k = 0;
        while (!stack.isEmpty()) {
            result[k] = stack.pop();
            k++;
        }
        return result;
    }
}