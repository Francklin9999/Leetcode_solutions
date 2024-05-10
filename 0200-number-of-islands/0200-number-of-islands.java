class Solution {
    public int numIslands(char[][] grid) {
        Queue<int[]> queue = new ArrayDeque<>();
        int count = 0;
        int ROWS = grid.length;
        int COLMN = grid[0].length;
        int[][] neighbours = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLMN; j++) {
                if (grid[i][j] == '0') continue;
                count++;
                int[] pair = new int[2];
                pair[0] = i;
                pair[1] = j;
                queue.add(pair);
                while (!queue.isEmpty()) {
                    int[] curr = queue.poll();
                    int r = curr[0];
                    int c = curr[1];
                    for (int [] neighbour : neighbours) {
                        int newR = r + neighbour[0], newL = c + neighbour[1];
                        if (Math.min(newR, newL) < 0 || newR == ROWS || newL == COLMN ||
                        grid[newR][newL] == '0') continue;
                        queue.offer(new int[]{newR, newL});
                        grid[newR][newL] = '0';
                    }
                }
            }
        }
        return count;
    }
}