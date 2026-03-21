class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;

        int l = 0;
        int r = 0;
        int maxLength = 0;

        for (; r < s.size(); r++) {
            auto it = map.find(s[r]);
            if (it != map.end()) {
                maxLength = max(maxLength, r - l);
                l = max(l, it->second + 1);
            }

            map[s[r]] = r;
        }

        return max(maxLength, r - l);
    }
};