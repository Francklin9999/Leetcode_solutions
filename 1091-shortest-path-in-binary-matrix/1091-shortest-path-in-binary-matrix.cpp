class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;
        int path = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> queue;
        vector<vector<int>> ajd = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        queue.push(pair(0, 0));
        grid[0][0] = -1;

        while (!queue.empty()) {
            path++;
            int size = queue.size();
            for (int s = 0; s < size; s++) {
                auto& curr = queue.front();

                if (curr.first == ROWS - 1 && curr.second == COLS - 1) return path;
                for (int i = 0; i < ajd.size(); i++) {
                    int row = curr.first + ajd[i][0];
                    int col = curr.second + ajd[i][1];

                    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && grid[row][col] == 0) {
                        grid[row][col] = -1;
                        queue.push(pair(row, col));
                    }
                }

                queue.pop();
            }
        }

        return -1;
    }
};