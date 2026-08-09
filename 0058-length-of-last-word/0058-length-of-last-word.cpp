class Solution {
public:
    int lengthOfLastWord(string s) {
        auto i = s.size() - 1;

        while(s[i] == ' ') i--;

        int l{};
        while(i < s.size() && s[i] != ' ') {
            l++;
            i--;
        }

        return l;
    }
};