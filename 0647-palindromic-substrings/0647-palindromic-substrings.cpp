class Solution {
public:
    int countSubstrings(string s) {
        int number = 0;

        int l;
        int r;

        for (int i = 0; i < s.size(); ++i) {
            l = i;
            r = i;

            while (l >= 0 && r < s.size() && s.at(r) == s.at(l)) {
                ++number;
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s.at(r) == s.at(l)) {
                ++number;
                l--;
                r++;
            }
        }

        return number;
    }
};