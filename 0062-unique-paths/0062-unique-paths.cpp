class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m + 1, vector<int>(n + 1));
        res[0][1] = 1;

        for (auto i = 1uz; i <= m; ++i) {
            for (auto j = 1uz; j <= n; ++j) {
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }

        return res[m][n];
    }
};