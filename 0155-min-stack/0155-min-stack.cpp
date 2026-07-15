class MinStack {
stack<pair<int, int>> minStack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if (minStack.empty()) {
            minStack.push(
                pair(value, value)
            );
        } else {
            minStack.push(
                pair(value, min(value, minStack.top().second))
            );
        }
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */