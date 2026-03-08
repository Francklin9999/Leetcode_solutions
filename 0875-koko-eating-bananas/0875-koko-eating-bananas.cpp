class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minR = INT_MAX;
        double l = 0;
        double r = *(std::max_element(piles.begin(), piles.end()));

        while (l <= r) {
            int mid = l + (r - l) / 2;

            double numbersOfHours = 0;
            for (int i = 0; i < piles.size(); ++i) {
                numbersOfHours += std::ceil(((double) piles[i]) / mid);
            }

            if (numbersOfHours <= h) {
                minR = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return minR;
    }
};