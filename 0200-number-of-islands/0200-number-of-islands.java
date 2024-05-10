class Solution {
    public int numIslands(char[][] grid) {
        Queue<int[]> queue = new LinkedList<>();
        int count = 0;
        int ROWS = grid.length;
        int COLMN = grid[0].length;
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLMN; j++) {
                if (grid[i][j] == '0') continue;
                count++;
                int[] pair = new int[2];
                pair[0] = i;
                pair[1] = j;
                queue.add(pair);
                while (!queue.isEmpty()) {
                    int size = queue.size();
                    for (int k = 0; k < size; k++) {
                        int[] curr = queue.poll();
                        int r = curr[0];
                        int c = curr[1];
                        // if (grid[r][c] == '0') continue;
                        int[][] neighbords = {{r + 1, c}, {r, c + 1}, {r - 1, c}, {r, c - 1}};
                        for (int z = 0; z < 4; z++) {
                            int newR = neighbords[z][0], newL = neighbords[z][1];
                            if (Math.min(newR, newL) < 0 || newR == ROWS || newL == COLMN ||
                            grid[newR][newL] == '0') continue;
                            queue.offer(neighbords[z]);
                            grid[newR][newL] = '0';
                        }
                    }
                }
            }
        }
        return count;
    }
}