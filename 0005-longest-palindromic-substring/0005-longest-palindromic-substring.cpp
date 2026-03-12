class Solution {
public:
    string longestPalindrome(string s) {
        std::string max(1, s.at(0));
        int l;
        int r;

        for (int i = 0; i < s.size(); ++i) {
            l = i;
            r = i; 
            while (l >= 0 && r < s.size() && s.at(l) == s.at(r)) {
                if (r - l + 1 > max.size()) max = s.substr(l, r - l + 1);
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s.at(l) == s.at(r)) {
                if (r - l + 1 > max.size()) max = s.substr(l, r - l + 1);
                l--;
                r++;
            }
        }

        return max;
    }
};