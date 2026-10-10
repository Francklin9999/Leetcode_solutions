class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool is_neg{x < 0};
        int cp = std::abs(x);
        int n{};

        while (cp > 0) {
            if (n > std::numeric_limits<int>::max() / 10) return 0;
            n *= 10;
            n += cp % 10;
            cp /= 10;
        }

        return is_neg ? n * - 1: n;
    }
};