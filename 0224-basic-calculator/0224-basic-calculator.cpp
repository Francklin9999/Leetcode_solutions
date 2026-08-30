class Solution {

pair<int, int> helper(string& s, int idx) {
    int res{};
    int sign{1};

    while (idx < s.size()) {
        if (s[idx] == ' ') {
            ++idx;
        } else if (s[idx] == '+') {
            sign = 1;
            ++idx;
        } else if (s[idx] == '-') {
            sign = -1;
            ++idx;
        } else if (s[idx] == '(') {
            auto t = helper(s, idx + 1);
            res += sign * t.first;
            idx = t.second;
        } else if (s[idx] == ')') {
            return {res, idx + 1};
        } else {
            long long num{};

            while (idx < s.size() && isdigit(s[idx])) {
                num = num * 10 + (s[idx] - '0');
                ++idx;
            }

            res += sign * num;
        }
    }

    return {res, idx};
}
public:
    int calculate(string s) {
        return helper(s, 0).first;
    }
};