class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l{}, r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int x = mid / n;
            int y = mid % n;

            if (matrix[x][y] > target) r = mid - 1;
            else if (matrix[x][y] < target) l = mid + 1;
            else return true;
        }

        return false;
    }
};