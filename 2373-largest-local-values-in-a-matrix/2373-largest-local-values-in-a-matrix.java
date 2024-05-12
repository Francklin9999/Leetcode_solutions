class Solution {
    public int[][] largestLocal(int[][] grid) {
        int[][] anw = new int[grid.length - 2][grid[0].length - 2];
        int currmax;
        for (int k = 0; k < grid[0].length - 2; k++) {
            for (int i = 0; i < grid.length - 2; i++) {
                currmax = 0;
                for (int j = k; j < k + 3; j++) {
                    for (int z = i; z < i + 3; z++) {
                        currmax = Math.max(currmax, grid[j][z]);
                    }
                }
                anw[k][i] = currmax;
            }
        }
        return anw;
    }
}