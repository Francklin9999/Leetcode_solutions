class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int len{};

        for (auto l{0uz}, r{0uz}; r < s.size(); ++r) {
            while (seen.count(s[r])) seen.erase(s[l++]);

            seen.insert(s[r]);
            len = std::max(len, static_cast<int>(r - l + 1));
        }

        return len;
    }
};