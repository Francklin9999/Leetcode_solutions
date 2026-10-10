class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen(256, false);
        int len{};

        for (auto l{0uz}, r{0uz}; r < s.size(); ++r) {
            while (seen[s[r]]) seen[s[l++]] = false;

            seen[s[r]] = true;
            len = std::max(len, static_cast<int>(r - l + 1));
        }

        return len;
    }
};