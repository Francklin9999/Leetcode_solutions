class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);

        int l{}, r{};
        int n = s.size();
        int longest{1};

        for (; r < n; ++r) {
            ++count[s[r] - 'A'];

            int m = *std::max_element(count.begin(), count.end());

            if (r - l + 1 - m > k) {
                longest = std::max(longest, r - l);
                --count[s[l++] - 'A'];
            }
        }

        return std::max(longest, r - l);
    }
};