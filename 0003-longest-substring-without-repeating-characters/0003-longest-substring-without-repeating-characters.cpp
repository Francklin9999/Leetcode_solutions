class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int l = 0;
        int r = 0;
        int maxLength = 0;

        while (r < s.size()) {
            if(set.contains(s[r])) {
                set.erase(s[l]);
                l++;
            } else {
                set.insert(s[r]);
                maxLength = max(maxLength, r - l + 1);
                r++;
            }
        }

        return maxLength;
    }
};