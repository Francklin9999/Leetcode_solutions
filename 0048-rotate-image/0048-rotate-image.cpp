class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        for (int i{0}; i < n; ++i) {
            for (int j{i + 1}; j < m; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i{0}; i < matrix.size(); ++i) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};