class MyQueue {
stack<int> stack1;
stack<int> stack2;
    int helper() {
        int curr;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        auto curr = helper();
        stack2.pop();
        return curr;
    }
    
    int peek() {
        return helper();
    }
    
    bool empty() {
        return (stack1.empty() && stack2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */