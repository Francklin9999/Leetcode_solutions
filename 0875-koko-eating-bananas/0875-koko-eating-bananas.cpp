class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *std::max_element(piles.begin(), piles.end());
        int min{max};

        int l{};
        int r{max};

        while (l <= r) {
            int mid = l + (r - l) / 2;
            cout << mid;

            if (helper(piles, h, mid)) {
                min = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return min;
    }

    bool helper(vector<int>& piles, int h, int mid) {
        double hours{};

        for (auto i = 0uz; i < piles.size(); ++i) {
            hours += std::ceil((double) piles[i] / (double) mid);
        }

        return hours <= h;
    }
};