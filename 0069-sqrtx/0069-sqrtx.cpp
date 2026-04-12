class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = 46341;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            unsigned long long curr = (unsigned long long) mid * mid;

            if (curr > x) r = mid - 1;
            else if (curr < x) l = mid + 1;
            else return mid;
        }

        return r;
    }
};