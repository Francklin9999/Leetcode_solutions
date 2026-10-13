class Solution {
static constexpr int nei[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        std::queue<pair<int, int>> queue;
        int number_of_islands{0};
        int m = grid.size(), n = grid[0].size();

        for (auto i{0uz}; i < m; ++i) {
            for (auto j{0uz}; j < n; ++j) {
                if (grid[i][j] != '1') continue;
                queue.emplace(i, j);
                while (!queue.empty()) {
                    auto& front = queue.front();

                    for (auto k{0uz}; k < 4; ++k) {
                        int x = nei[k][0] + front.first;
                        int y = nei[k][1] + front.second;

                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') continue;
                        grid[x][y] = '0';
                        queue.emplace(x, y);
                    }

                    grid[front.first][front.second] = '0';
                    queue.pop();
                }
                number_of_islands++;
            }
        }

        return number_of_islands;
    }
};