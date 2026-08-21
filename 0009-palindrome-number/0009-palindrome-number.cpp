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

        while (m > 0 && x > 0) {
            if (m % 10 != x % 10) return false;

            m /= 10;
            x /= 10;
        }

        return true;
    }
};