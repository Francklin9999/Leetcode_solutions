class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;

        int l = 0;
        int r = 0;
        int maxLength = 0;

        while (r < s.size()) {
            auto it = map.find(s[r]);
            if (it != map.end()) {
                int pos = max(l + 1, it->second + 1);
                while (l < pos) {
                    map.erase(s[l]);
                    l++;
                }
            } else {
                map.insert({s[r], r});
                maxLength = max(maxLength, r - l + 1);
                r++;
            }
        }

        return maxLength;
    }
};