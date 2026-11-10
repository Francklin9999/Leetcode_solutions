class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l{0}, r = n - 1;
        int top{0}, bottom = n - 1;
        int c{1};

        vector<vector<int>> res(n, vector<int>(n));

        while (l <= r && top <= bottom) {
            for (int i{l}; i <= r; ++i) {
                res[top][i] = c++;
            }
            ++top;

            for (int i{top}; i <= bottom; ++i) {
                res[i][r] = c++;
            }
            --r;

            if (top <= bottom) {
                for (int i{r}; i >= l; --i) {
                    res[bottom][i] = c++;
                }
                --bottom;
            }

            if (l <= r) {
                for (int i{bottom}; i >= top; --i) {
                    res[i][l] = c++;
                }
                ++l;
            }
        }

        return res;   
    }
};