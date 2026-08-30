class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res{}, l{}, r{}, n = colors.size();

        while (l < n) {
            while (l < n && r - l + 1 < k) {
                if (colors[r % n] == colors[(r + 1) % n]) l = r + 1;
                ++r;
            }

            if (l < n && r - l + 1 == k) ++res;

            ++l;
        }

        return res;
    }
};