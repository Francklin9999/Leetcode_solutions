class Solution {
int helper(string s, string& local) {
    int num{};
    for (auto i{0uz}; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            num *= 10;
            num += s[i] - '0';
        } else if (s[i] == '[') {
            string l{};
            i += helper(s.substr(i + 1), l) + 1;
            for (int j{0}; j < num; ++j) local += l;
            num = 0;
        } else if (s[i] == ']') {
            return i;
        } else {
           local.push_back(s[i]);
        }
    }

    return s.size();
}
public:
    string decodeString(string s) {
        string local{};
        helper(s, local);
        return local;
    }
};