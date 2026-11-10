class Solution {
static constexpr int nei[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;


        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (mat[i][j] == 0) q.emplace(i, j);
                else mat[i][j] = -1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto [_x, _y] : nei) {
                auto n_x = x + _x;
                auto n_y = y + _y;

                if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m || mat[n_x][n_y] != -1) continue;

                mat[n_x][n_y] = mat[x][y] + 1;
                q.emplace(n_x, n_y);
            }
        }

        return mat;
    }
};