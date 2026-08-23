class Solution {
public:
    bool sumGame(string num) {
        int half = num.size() / 2;
        int count1{}, count2{};
        int alice{}, bob{};

        for (auto i{0uz}; i < half; ++i) {
            if (num[i] == '?') ++count1;
            else bob += num[i] - '0';
        }

        for (auto i{half}; i < num.size(); ++i) {
            if (num[i] == '?') ++count2;
            else alice += num[i] - '0';
        }

        if ((count1 + count2) % 2 == 0 && 2 * (bob - alice) == 9 * (count2 - count1)) return false;

        return true;
    }
};