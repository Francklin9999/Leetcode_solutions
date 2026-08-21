class Solution {
bool isPossible(vector<int>& weights, int days, int w) {
    int day{};
    int curr{};

    for (auto i{0uz}; i < weights.size(); ++i) {
        if (curr + weights[i] > w) {
            ++day;
            curr = 0;
        }

        curr += weights[i];
    }

    return ++day <= days;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l{*std::max_element(weights.begin(), weights.end())};
        int r{INT_MAX};

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (isPossible(weights, days, mid)) r = mid;
            else l = mid + 1;
        }

        return r;
    }
};