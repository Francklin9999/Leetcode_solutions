class Solution {
long long mod = 1e9+7;
public:
    int countHousePlacements(int n) {
        if (n == 1) return 4;
        long prev1{3}, prev2{2};

        for (int i{2}; i < n; ++i) {
            auto tmp = prev1;
            prev1 = (prev1 + prev2) % mod;
            prev2 = tmp;
        }

        return (prev1 * prev1) % mod;
    }
};