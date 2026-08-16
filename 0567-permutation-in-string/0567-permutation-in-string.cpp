class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);
        vector<int> window(26, 0);

        int sz = s1.size();

        for (char c : s1) {
            ++count[c - 'a'];
        }

        int l{};
        for (auto i{0uz}; i < s2.size(); ++i) {
            ++window[s2[i] - 'a'];

            if (i - l + 1 > sz) {
                --window[s2[l++] - 'a'];
            }

            if (count == window) return true;
        }

        return false;
    }
};