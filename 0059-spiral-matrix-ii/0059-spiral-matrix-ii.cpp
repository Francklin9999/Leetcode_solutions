class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l{}, r = n - 1;
        int top{}, bottom = n - 1;
        int curr{1};

        vector<vector<int>> res(n, vector<int>(n));

        while (l <= r && top <= bottom) {
            for (int i{l}; i <= r; ++i) {
                res[top][i] = curr++; 
            }
            ++top;

            for (int i{top}; i <= bottom; ++i) {
                res[i][r] = curr++;
            }
            --r;

            if (l <= r) {
                for (int i{r}; i >= l; --i) {
                    res[bottom][i] = curr++;
                }
                --bottom;
            }

            if (top <= bottom) {
                for (int i{bottom}; i >= top; --i) {
                    res[i][l] = curr++;
                }
                ++l;
            }
        }

        return res;
    }
};