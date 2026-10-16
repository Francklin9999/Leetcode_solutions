class Solution {
private:
    constexpr static int nei[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> seen(m, std::vector<bool>(n, false));

        int max_fish{};

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (grid[i][j] == 0 || seen[i][j]) continue;

                q.emplace(i, j);
                seen[i][j] = true;
                int curr{};

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    curr += grid[x][y];

                    for (const auto& vec : nei) {
                        auto nx = x + vec[0];
                        auto ny = y + vec[1];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0 || seen[nx][ny]) continue;

                        seen[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }

                max_fish = std::max(max_fish, curr);
            }
        }

        return max_fish;
    }
};