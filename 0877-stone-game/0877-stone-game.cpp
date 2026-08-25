class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice{}, bob{};
        int l = 0, r = piles.size() - 1;
        bool turn{true};

        while (l <= r) {
            auto left = piles[l];
            if (l + 1 <= r) left += piles[l + 1];

            auto right = piles[r];
            if (r - 1 >= l) right += piles[r - 1];

            auto& p = turn ? alice : bob;
            turn = !turn;

            if (left > right) {
                p += left;
                ++l;
            } else {
                p += right;
                --r;
            }
        }

        return alice > bob;
    }
};