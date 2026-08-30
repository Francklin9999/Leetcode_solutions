class Solution {
public:
    int appendCharacters(string s, string t) {
        size_t l{};

        for (auto i{0uz}; i < s.size(); ++i) {
            if (l == t.size()) break;

            if (t[l] == s[i]) ++l;
        }

        return t.size() - l;
    }
};