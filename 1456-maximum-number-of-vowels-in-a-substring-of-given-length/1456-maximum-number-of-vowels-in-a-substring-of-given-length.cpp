class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        int res{}, curr{};
        int l{};
        
        for (auto r{0uz}; r < s.size(); ++r) {
            curr += vowel.count(s[r]);

            if (r - l + 1 > k) {
                curr -= vowel.count(s[l++]);
            }

            res = std::max(res, curr);
        }

        return res;
    }
};