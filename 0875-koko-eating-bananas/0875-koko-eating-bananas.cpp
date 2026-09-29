class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l{1};
        int r = *std::max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (check(piles, h, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    bool check(vector<int>& piles, int h, double m) {
        int t{0};
        for (int p : piles) {
            t += static_cast<int>(std::ceil(p / m));
        }

        return t <= h;
    }
};