class Solution {
bool isPossible(vector<int>& piles, int h, int speed) {
    int hours{};

    for (auto i{0uz}; i < piles.size(); ++i) {
        hours += piles[i] / speed;
        if (piles[i] % speed != 0) ++hours;
    }

    return hours <= h;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l{1};
        int r{*std::max_element(piles.begin(), piles.end())};

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (isPossible(piles, h, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }
};