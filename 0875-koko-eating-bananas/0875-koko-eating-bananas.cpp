class Solution {
bool helper(vector<int>& piles, int h, int mid) {
    int hours{};
    for (auto i{0uz}; i < piles.size(); ++i) {
        hours += std::ceil(piles[i] / static_cast<double>(mid));
        if (hours > h) return false;
    }

    return true;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low{1}, high{*std::max_element(piles.begin(), piles.end())};

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (helper(piles, h, mid)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};