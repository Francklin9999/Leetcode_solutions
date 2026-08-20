class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};

        int l{}, r{}, m{};
        int n = s.size();
        int longest{1};

        for (; r < n; ++r) {
            ++count[s[r] - 'A'];

            m = std::max(m, count[s[r] - 'A']);

            if (r - l + 1 - m > k) {
                longest = std::max(longest, r - l);
                --count[s[l++] - 'A'];
            }
        }

        return std::max(longest, r - l);
    }
};