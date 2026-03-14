class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> queue;

        vector<vector<int>> ajd = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int maxLenght = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                queue.push(pair(i, j));
                int len = 1;
                grid[i][j] = 0;

                while (!queue.empty()) {
                    auto curr = queue.front();
                    queue.pop();

                    for (int k = 0; k < ajd.size(); ++k)  {
                        int row = curr.first + ajd[k][0];
                        int col = curr.second + ajd[k][1];

                        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && grid[row][col] == 1) {
                            ++len;
                            queue.push(pair(row, col));
                            grid[row][col] = 0;
                        }
                    }

                }

                maxLenght = std::max(maxLenght, len);
            }
        }

        return maxLenght;
    }
};