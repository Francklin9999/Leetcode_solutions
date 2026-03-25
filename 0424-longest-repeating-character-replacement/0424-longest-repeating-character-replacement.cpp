class Solution {
public:
    int characterReplacement(string s, int k) {
        int l, r = 0;
        int len = 0;
        int maxL = 0;
        int freq[26] = {0};

        for (; r < s.size(); r++) {
            maxL = std::max(maxL, ++freq[s.at(r) - 'A']);

            if (r - l + 1 - maxL > k) {
                len = std::max(len, r - l);
                freq[s.at(l) - 'A']--;
                l++;
            }
        }

        return std::max(len, r - l);
    }
};