class Solution {
constexpr static int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int islands{};

        for (auto i{0uz}; i < m; ++i) {
            for (auto j{0uz}; j < n; ++j) {
                if (grid[i][j] != '1') continue;
                q.push({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    grid[x][y] = '2';
                    for (auto d : directions) {
                        auto x1 = x + d[0];
                        auto y1 = y + d[1];
                        if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n || grid[x1][y1] != '1') continue;
                        grid[x1][y1] = '2';
                        q.push({x1, y1}); 
                    }
                }

                ++islands;
            }
        }

        return islands;        
    }
};