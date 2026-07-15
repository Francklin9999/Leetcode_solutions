class Solution {
static constexpr int division(int a, int b) {
    return a / b;
}

static constexpr int multiplication(int a, int b) {
    return a * b;
}

static constexpr int addition(int a, int b) {
    return a + b;
}

static constexpr int soustraction(int a, int b) {
    return a - b;
}

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        unordered_map<string, std::function<int(int, int)>> map;
        map["+"] = addition;
        map["-"] = soustraction;
        map["/"] = division;
        map["*"] = multiplication;

        for (string s : tokens) {
            if (map.find(s) == map.end()) {
                stack.push(stoi(s));
            } else {
                auto first = stack.top();
                stack.pop();
                auto second = stack.top();
                stack.pop();
                stack.push(map[s](second, first));
            }
        }

        return stack.top();
    }
};