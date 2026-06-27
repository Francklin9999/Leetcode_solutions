class Solution {
public:
    bool validPalindrome(string s) {
        std::size_t l{0};
        std::size_t r(s.size() - 1);

        while (l < r) {
            if (s.at(l) != s.at(r)) {
                return (isValid(s.substr(l, r - l)) || isValid(s.substr(l + 1, r - l)));
            } else {
                l++;
                r--;
            }
        }

        return true;
    }

    bool isValid(string s) {
        std::size_t l{0};
        std::size_t r(s.size() - 1);

        while (l < r) {
            if (s.at(l) != s.at(r)) {
                return false;
            } else {
                l++;
                r--;
            }
        }

        return true;
    }
};