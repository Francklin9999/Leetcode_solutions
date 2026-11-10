class Solution {
static constexpr int nei[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        std::queue<std::pair<int, int>> q;

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.emplace(i, j);
                }
                else isWater[i][j] = -1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto [_x, _y] : nei) {
                auto n_x = x + _x;
                auto n_y = y + _y;

                if (n_x < 0 || n_x >= m || n_y < 0 || n_y >= n || isWater[n_x][n_y] != -1) continue;

                isWater[n_x][n_y] = isWater[x][y] + 1;
                q.emplace(n_x, n_y);
            }
        }

        return isWater;
    }
};