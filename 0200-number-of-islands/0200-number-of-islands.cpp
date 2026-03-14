class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<int>> visited(ROWS, vector<int>(COLS));
        queue<pair<int, int>> queue;
        vector<vector<int>> ajd = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int count = 0;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == '0' || visited[i][j] == 1) continue;
                queue.push(pair(i, j));
                while (!queue.empty()) {
                    auto curr = queue.front();
                    queue.pop();
                    for (int k = 0; k < ajd.size(); ++k) {
                        int l = curr.first + ajd[k][0];
                        int r = curr.second + ajd[k][1];

                        if (l >= 0 && l < ROWS && r >= 0 && r < COLS && grid[l][r] == '1' && visited[l][r] != 1) {
                            visited[l][r] = 1;
                            queue.push(pair(l, r));
                        }
                    }
                }
                ++count;
            }
        }
        return count;
    }
};