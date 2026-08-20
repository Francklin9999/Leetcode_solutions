class Solution {
int getNextChar(string& s, int i)  {
    int skip{};

    while (i >= 0) {
        if (s[i] == '#') {
            ++skip;
            --i;
        } else if (skip > 0) {
            --skip;
            --i;
        } else {
            break;
        }
    }

    if (i < 0) return -1;

    return i;
}
public:
    bool backspaceCompare(string s, string t) {
        int l = s.size() - 1;
        int r = t.size() - 1;

        while (l >= 0 && r >= 0) {
            auto n1 = getNextChar(s, l);
            auto n2 = getNextChar(t, r);

            if (n1 == -1 && n2 == -1) return true;
            if (n1 == -1 || n2 == -1) return false;
            if (s[n1] != t[n2]) return false;

            l = n1 - 1;
            r = n2 - 1;
        }

        auto n1 = getNextChar(s, l);
        auto n2 = getNextChar(t, r);

        if (n1 >= 0 || n2 >= 0) return false;

        return true;
    }
};