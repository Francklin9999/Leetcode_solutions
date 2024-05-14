class Solution {

    int max = 0;
    Set<Pair<Integer, Integer>> visited = new HashSet<>();

    public int getMaximumGold(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 0) {
                    max = Math.max(max, dfs(grid, i, j));
                }
            }
        }
        return max;
    }
    
    private int dfs(int[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.length || j == grid[0].length ||
        grid[i][j] == 0 || visited.contains(new Pair<>(i, j))) return 0;

        visited.add(new Pair<>(i, j));

        int left = dfs(grid, i - 1, j);
        int right = dfs(grid, i + 1, j);
        int up = dfs(grid, i, j + 1);
        int down = dfs(grid, i, j - 1);

        visited.remove(new Pair<>(i, j));

        int localmax = Math.max(Math.max(left, right), Math.max(up, down));
        max = Math.max(max, localmax);

        return grid[i][j] + localmax;
    }
}