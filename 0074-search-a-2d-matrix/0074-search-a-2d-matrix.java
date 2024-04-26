class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int l = 0, r = matrix[0].length - 1, middle;
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][matrix[0].length - 1] == target) return true;
            if (matrix[i][matrix[0].length - 1] < target) {
                continue;
            }
            while (l <= r) {
                middle = l + (r - l) / 2;
                if (matrix[i][middle] < target) l = middle + 1;
                if (matrix[i][middle] > target) r = middle - 1;
                if (matrix[i][middle] == target) return true;
            }
        }
      return false;
    }
}