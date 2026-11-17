class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int top{}, low = grid.size() - 1; // rows
        int l{}, r = grid[0].size() - 1; // cols

        while (top <= low && l <= r) {
            int perimeter = 2 * (low - top) + 2 * (r - l);
            int rotation = k % perimeter;

            for (int i = 0; i < rotation; ++i) {
                int tmp = grid[top][l];

                for (int j = top + 1; j <= low; ++j) {
                    swap(grid[j][l], tmp);
                }

                for (int j = l + 1; j <= r; ++j) {
                    swap(grid[low][j], tmp);
                }

                for (int j = low - 1; j >= top; --j) {
                    swap(grid[j][r], tmp);
                }

                for (int j = r - 1; j >= l; --j) {
                    swap(grid[top][j], tmp);
                }
            }

            ++top;
            ++l;
            --low;
            --r;
        }

        return grid;
    }
};