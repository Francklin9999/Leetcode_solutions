class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        size_t m{grid.size()};
        size_t n{grid[0].size()};
        int total{};
        bool flag{false};
        queue<pair<int, int>> queue;
        vector<vector<int>> nei{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto i = 0uz; i < m; ++i) {
            for (auto j = 0uz; j < n; ++j) {
                if (grid[i][j] == 2) queue.emplace(i, j);
            }
        }

        while (!queue.empty()) {
            auto sz = queue.size();
            flag = false;
            for (auto i = 0; i < sz; i++) {
                auto curr = queue.front();
                queue.pop();

                for (auto e : nei) {
                    auto x = curr.first + e[0];
                    auto y = curr.second + e[1];

                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    queue.emplace(x, y);
                    flag = true;
                }
            }
            if (flag)
                total++;
        }

        for (auto i = 0uz; i < m; ++i) {
            for (auto j = 0uz; j < n; ++j) {
                if (grid[i][j] == 1) return -1;       
            }
        }

        return total;
    }
};