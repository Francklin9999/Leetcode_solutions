class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        int total = 0;
        int[][] nei = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                queue.offer(new Pair<Integer, Integer>(i, j));
                grid[i][j] = '0';
                while (!queue.isEmpty()) {
                    var top = queue.poll();
                    for (var idx : nei) {
                        var x = top.getKey() + idx[0];
                        var y = top.getValue() + idx[1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') continue;
                        queue.offer(new Pair<Integer, Integer>(x, y));
                        grid[x][y] = '0';
                    }
                }
                total++;
            }
        }

        return total;
    }
}