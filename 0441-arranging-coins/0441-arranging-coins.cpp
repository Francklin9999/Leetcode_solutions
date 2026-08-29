class Solution {
public:
    int arrangeCoins(int n) {
        int i{};

        while (n >= 0) {
            ++i;
            n -= i;
        }

        return i - 1;
    }
};