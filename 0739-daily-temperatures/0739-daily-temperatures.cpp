class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(), 0);
        stack<pair<int, int>> stack;

        for (auto i{0uz}; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[i] > stack.top().first) {
                out[stack.top().second] = i - stack.top().second;
                stack.pop();
            }

            stack.emplace(temperatures[i], i);
        }

        return out;
    }
};