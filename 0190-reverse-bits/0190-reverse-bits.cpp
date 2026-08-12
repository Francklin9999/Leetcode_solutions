class Solution {
public:
    int reverseBits(int n) {
        int result{};
        int m = n;

        for (auto i = 0; i < 32; ++i) {
            result = (result << 1) + (m & 1);
            m = m >> 1;
        }

        return result;
    }
};