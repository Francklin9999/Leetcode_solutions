class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int org = x;
        long long num = 0;

        while (org != 0) {
            num = num * 10 + org % 10;
            org = org / 10;
        }

        return num == x;
    }
};