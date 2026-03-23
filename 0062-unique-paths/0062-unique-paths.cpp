class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[m - 1][n - 1] = 1;

        for  (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                grid[i][j] = 0;
                int col = j + 1; 
                if (col < grid[0].size()) grid[i][j] += grid[i][col];
                int row = i + 1; 
                if (row < grid.size()) grid[i][j] += grid[row][j];
            }
        }

        return grid[0][0];        
    }
};