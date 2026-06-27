class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t l{0uz};
        size_t r{s.size() - 1};
        char tmp;

        while (l < r) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};