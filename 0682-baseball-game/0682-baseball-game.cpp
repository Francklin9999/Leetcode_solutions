class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "D") {
                int top = stack.top();
                stack.push(2 * top);
            } else if (operations[i] == "C") {
                stack.pop();
            } else if (operations[i] == "+") {
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.push(first);
                stack.push(first + second);
            } else {
                stack.push(std::stoi(operations[i]));
            } 
        }

        if (stack.empty()) return 0;

        int sum = 0;
        while (!stack.empty()) {
            sum += stack.top();
            stack.pop();
        }

        return sum;
    }
};