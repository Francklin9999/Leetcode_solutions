
class MinStack {

    Stack<Pair<Integer, Integer>> stack;
    public MinStack() {
        stack = new Stack<>();
    }
    
    public void push(int val) {
        if (!stack.isEmpty()) {
            Pair<Integer, Integer> curr = new Pair<>
            (val, Math.min(val, stack.peek().getValue()));
            stack.push(curr);
        } else {
            Pair<Integer, Integer> curr = new Pair<>(val, val);
            stack.push(curr);
        }
        return;

    }
    
    public void pop() {
        stack.pop();
        return;
    }
    
    public int top() {
        return stack.peek().getKey();
    }
    
    public int getMin() {
        return stack.peek().getValue();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */