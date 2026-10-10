class Solution {
public:
    bool isPalindrome(int x) {
        int cp{x};
        int cmp{};

        while (cp > 0) {
            if (cmp > std::numeric_limits<int>::max() / 10) return false;
            cmp *= 10;
            cmp += cp % 10;
            cp /= 10;
        }

        return cmp == x;
    }
};