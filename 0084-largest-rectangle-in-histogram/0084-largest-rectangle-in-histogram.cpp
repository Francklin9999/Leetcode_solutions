class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res{};
        stack<pair<int, int>> stack;

        for (auto i{0uz}; i < heights.size(); ++i) {
            int j = i;
            while (!stack.empty() && heights[i] < stack.top().first) {
                res = std::max(res, stack.top().first * (static_cast<int>(i) - stack.top().second));
                j = stack.top().second;
                stack.pop();
            }
            stack.push(pair<int, int>(heights[i], j));
        }

        while (!stack.empty()) {
            res = std::max(res, stack.top().first * (static_cast<int>(heights.size()) - stack.top().second));
            stack.pop();
        }

        return res;
    }
};