class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l{}, r = matrix[0].size() - 1;
        int top{}, bottom = matrix.size() - 1;

        vector<int> spiral;
        spiral.reserve(matrix.size() * matrix[0].size());

        while (l <= r && top <= bottom) {
            for (int i{l}; i <= r; ++i) {
                spiral.push_back(matrix[top][i]);
            }
            ++top;

            for (int i{top}; i <= bottom; ++i) {
                spiral.push_back(matrix[i][r]);
            }
            --r;

            if (top <= bottom) {
                for (int i{r}; i >= l; --i) {
                    spiral.push_back(matrix[bottom][i]);
                }
            }
            --bottom;

            if (l <= r) {
                for (int i{bottom}; i >= top; --i) {
                    spiral.push_back(matrix[i][l]);
                }
            }
            ++l;
        }

        return spiral;
    }
};