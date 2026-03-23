class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();
        vector<vector<long long>> dp(ROWS, vector<long long>(COLS));
        if (obstacleGrid[ROWS - 1][COLS - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        dp[ROWS - 1][COLS - 1] = -1;

        for (int i = ROWS - 1; i >= 0; i--) {
            for (int j = COLS - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) continue;
                if (j + 1 < COLS && obstacleGrid[i][j + 1] != 1) {
                    dp[i][j] += dp[i][j + 1];
                }
                if (i + 1 < ROWS && obstacleGrid[i + 1][j] != 1) {
                    dp[i][j] += dp[i + 1][j];
                }
            }
        }

        return -dp[0][0];
    }
};