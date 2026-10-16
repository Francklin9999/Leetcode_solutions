class Solution {
private:
    constexpr static int nei[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<bool>> seen(m, std::vector<bool>(n));
        std::queue<std::pair<int, int>> q;
        std::queue<std::pair<int, int>> proxy;

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (grid[i][j] == 0) continue;

                q.emplace(i, j);
                proxy.emplace(i, j);
                seen[i][j] = true;

                while (!proxy.empty()) {
                    auto [x, y] = proxy.front();
                    proxy.pop();

                    for (const auto& vec : nei) {
                        auto nx = x + vec[0];
                        auto ny = y + vec[1];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0 || seen[nx][ny]) continue;

                        q.emplace(nx, ny);
                        proxy.emplace(nx, ny);
                        seen[nx][ny] = true;
                    }
                }

                goto done;
            }
        }

        done:
        int shortest{0};

        while (!q.empty()) {
            auto sz = q.size();
            for (std::size_t i{0}; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (const auto& vec : nei) {
                    auto nx = x + vec[0];
                    auto ny = y + vec[1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || seen[nx][ny]) continue;

                    if (grid[nx][ny] == 1) return shortest;

                    q.emplace(nx, ny);
                    seen[nx][ny] = true;
                }
            }

            ++shortest;
        }


        return shortest;
    }
};