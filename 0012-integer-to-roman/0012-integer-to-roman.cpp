class Solution {
public:
    string intToRoman(int num) {
        string res{};

        while (num / 1000 > 0) {
            res.push_back('M');
            num -= 1000;
        }

        while (num / 900 > 0) {
            res.push_back('C');
            res.push_back('M');
            num -= 900;
        }

        while (num / 500 > 0) {
            res.push_back('D');
            num -= 500;
        }

        while (num / 400 > 0) {
            res.push_back('C');
            res.push_back('D');
            num -= 400;
        }

        while (num / 100 > 0) {
            res.push_back('C');
            num -= 100;
        }

        while (num / 90 > 0) {
            res.push_back('X');
            res.push_back('C');
            num -= 90;
        }

        while (num / 50 > 0) {
            res.push_back('L');
            num -= 50;
        }

        while (num / 40 > 0) {
            res.push_back('X');
            res.push_back('L');
            num -= 40;
        }

        while (num / 10 > 0) {
            res.push_back('X');
            num -= 10;
        }

        while (num / 9 > 0) {
            res.push_back('I');
            res.push_back('X');
            num -= 9;
        }

        while (num / 5 > 0) {
            res.push_back('V');
            num -= 5;
        }

        while (num / 4 > 0) {
            res.push_back('I');
            res.push_back('V');
            num -= 4;
        }

        while (num / 1 > 0) {
            res.push_back('I');
            num -= 1;
        }

        return res;
    }
};