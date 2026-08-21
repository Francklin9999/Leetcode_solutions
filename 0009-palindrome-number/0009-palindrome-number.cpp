class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int cp = x;
        long m{};

        while (cp > 0) {
            m *= 10;
            m += cp % 10;
            cp /= 10;
        }

        return m == x;
    }
};