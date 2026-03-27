class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int ROWS = mat.size();
        int COLS = mat[0].size();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int col = (j + k) % COLS;
                if (mat[i][j] != mat[i][col]) return false;
            }
        }

        return true;
    }
};