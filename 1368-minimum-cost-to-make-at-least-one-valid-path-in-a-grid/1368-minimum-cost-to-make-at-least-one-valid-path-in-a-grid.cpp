class Solution {
private:
    constexpr static int nei[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        std::deque<std::pair<int, int>> dq;
        std::vector<std::vector<int>> dest(m, std::vector<int>(n, INT_MAX));

        dq.emplace_back(0, 0);
        dest[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (std::size_t idx{0}; idx < 4; ++idx) {
                auto nx = x + nei[idx][0];
                auto ny = y + nei[idx][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int cost = (grid[x][y] == idx + 1) ? 0 : 1;

                if (dest[x][y] + cost >= dest[nx][ny]) continue;

                dest[nx][ny] = cost + dest[x][y];

                if (cost == 0) dq.emplace_front(nx, ny);
                else dq.emplace_back(nx, ny);
            }
        }

        return dest[m - 1][n - 1];
    }
};