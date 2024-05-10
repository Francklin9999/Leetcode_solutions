class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    maxArea = Math.max(maxArea, dfs(i, j, grid));
                }
            }
        }
        System.gc();
        return maxArea;
    }

    private int dfs (int i, int j, int[][] grid) {
        if (i < 0 || j < 0 || i >= grid.length || 
        j >= grid[0].length || grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        int count = 1;

        count += dfs(i + 1, j, grid);
        count += dfs(i - 1, j, grid);
        count += dfs(i, j + 1, grid);
        count += dfs(i, j - 1, grid);

        return count;
    }
}