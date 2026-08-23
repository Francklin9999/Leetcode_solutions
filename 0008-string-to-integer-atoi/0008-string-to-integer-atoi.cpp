class Solution {
public:
    int myAtoi(string s) {
        int idx{};
        bool negative{false};

        while (idx < s.size() && s[idx] == ' ') ++idx;
        if (idx < s.size() && s[idx] == '-') {
            negative = true;
            ++idx;
        }
        else if (idx < s.size() && s[idx] == '+') {
            negative = false;
            ++idx;
        }

        long long num{};
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            if (num > (INT_MAX - (s[idx] - '0')) / 10LL)
                return negative ? INT_MIN : INT_MAX;
    
            num *= 10;
            num += s[idx] - '0';
            ++idx;
        }

        return negative ? num * - 1: num;
    }
};