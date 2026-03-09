class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n < 3) return 1;
        vector<int> last3 = {0, 1, 1};

        for (int _ = 3; _ <= n; ++_) {
            int temp = last3[0] + last3[1] + last3[2];
            last3[0] = last3[1];
            last3[1] = last3[2];
            last3[2] = temp;
        }

        return last3[2];
    }
};