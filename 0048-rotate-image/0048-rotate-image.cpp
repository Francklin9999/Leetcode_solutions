class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (auto i = 0uz; i < matrix.size(); ++i) {
            for (auto j = i + 1; j < matrix.size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto i = 0uz; i < matrix.size(); ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};