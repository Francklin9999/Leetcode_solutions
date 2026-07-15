class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size());
        stack<pair<int, int>> stack;

        for (auto i = 0uz; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[i] > stack.top().first) {
                results[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push({temperatures[i], i});
        }

        while (!stack.empty()) {
            results[stack.top().second] = 0;
            stack.pop();
        }

        return results;
    }
};