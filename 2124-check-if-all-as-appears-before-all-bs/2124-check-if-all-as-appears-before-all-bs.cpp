class Solution {
public:
    bool checkString(string s) {
        size_t idx_a{0};
        size_t idx_b{s.size()};

        for (auto i{0uz}; i < s.size(); ++i) {
            if (s[i] == 'a') idx_a = i;
            else idx_b = i;

            if (idx_b < idx_a) return false;
        }

        return true;
    }
};