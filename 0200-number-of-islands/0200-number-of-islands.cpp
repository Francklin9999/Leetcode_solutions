class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> queue;
        vector<vector<int>> nei = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int total{};
        size_t m = grid.size();
        size_t n = grid[0].size();

        for (auto i = 0uz; i < m; ++i) {
            for (auto j = 0uz; j < n; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    total++;
                    queue.push(pair<int, int>(i, j));
                    while (!queue.empty()) {
                        auto curr = queue.front();
                        queue.pop();
                        for (auto e : nei) {
                            auto x = curr.first + e[0];
                            auto y = curr.second + e[1];

                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') continue;
                            grid[x][y] = '0';
                            queue.push(pair<int, int>(x, y));
                        }
                    }
                }
            }
        }


        return total;
    }
};