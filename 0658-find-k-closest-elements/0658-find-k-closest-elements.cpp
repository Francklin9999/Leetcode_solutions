class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l{}, r = arr.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            auto sum = x - arr[mid];

            if (sum < 0) r = mid - 1;
            else if (sum > 0) l = mid + 1;
            else {
                l = mid;
                r = mid;
                break;
            }
        }

        vector<int> res;
        res.reserve(k);

        while (r - l + 1 < k) {
            if (l - 1 < 0) r++;
            else if (r + 1 >= arr.size()) l--;
            else {
                if (std::abs(arr[l - 1] - x) > std::abs(arr[r + 1] - x)) r++;
                else l--;
            }
        }

        for (auto _{0uz}; _ < k; ++_) {
            res.push_back(arr[l++]);
        }

        return res;
    }
};