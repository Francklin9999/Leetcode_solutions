class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        constexpr long long mod = 1e9 + 7;
        long long a1{}, b1{};

        for (int i = 62; i >= 0 ; --i) {
            auto curr1 = (a >> i) & 1;
            auto curr2 = (b >> i) & 1;

            a1 <<= 1;
            b1 <<= 1;

            if (i >= n) {
                a1 |= curr1;
                b1 |= curr2;
            } else if (curr1 == curr2) {
                a1 |= 1;
                b1 |= 1;
            } else {
                if (a1 <= b1) {
                    a1 |= 1;
                } else {
                    b1 |= 1;
                }
            }
        }

        return ((a1 % mod) * (b1 % mod)) % mod;
    }
};