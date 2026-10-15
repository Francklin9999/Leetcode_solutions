class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        int l{0}, r{n};

        while (l <= r) {
            int mid = l + (r - l) / 2;

            auto res = std::pow(2, mid);

            if (res < n) l = mid + 1;
            else if (res > n) r = mid - 1;
            else return true;
        }

        return false;
    }
};