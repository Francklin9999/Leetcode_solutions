class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(), 0);
        stack<size_t> stack;

        for (auto i{0uz}; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                out[stack.top()] = i - stack.top();
                stack.pop();
            }

            stack.push(i);
        }

        return out;
    }
};