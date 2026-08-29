class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int i{n - 1}; i >= 0; --i) {
            curr[i] = 1;
            for (int j{i + 1}; j < n; ++j) {
                if (s[i] == s[j]) {
                    curr[j] = prev[j - 1] + 2;
                } else {
                    curr[j] = std::max(curr[j - 1], prev[j]);
                }
            }

            swap(curr, prev);
        }

        return prev[n - 1];
    }
};