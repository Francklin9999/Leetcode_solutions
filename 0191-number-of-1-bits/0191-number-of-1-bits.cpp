class Solution {
public:
    int hammingWeight(int n) {
        int number = 0;
        int k = n;

        while (k > 0) {
            if (k & 1)
                ++number;
            k = k >> 1;
        }

        return number;
    }
};