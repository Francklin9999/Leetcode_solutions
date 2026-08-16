class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;

        for (auto i{0uz}; i < matrix.size(); ++i) {
            for (auto j{0uz}; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto i{0uz}; i < matrix.size(); ++i) {
            for (auto j{0uz}; j < matrix[0].size(); ++j) {
                if (row.count(i) || col.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};