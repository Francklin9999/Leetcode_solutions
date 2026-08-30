class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l{};

        for (auto i{0uz}; i < t.size(); ++i) {
            if (l == s.size()) break;

            if (s[l] == t[i]) ++l;
        }


        return l == s.size();
    }
};