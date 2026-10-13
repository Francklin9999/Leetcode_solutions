class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int seq{};

        for (auto l{0uz}, r{0uz}; r < s.size(); ++r) {
            ++freq[s[r] - 'A'];

            auto curr_max = *std::max_element(freq.begin(), freq.end());

            while (l < r && r - l + 1 - curr_max > k) {
                --freq[s[l++] - 'A'];
                curr_max = *std::max_element(freq.begin(), freq.end());
            }

            seq = std::max(seq, static_cast<int>(r) - static_cast<int>(l) + 1); 
        }

        return seq;
    }
};