class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res{0}, curr{1};
        size_t l{0};

        for (auto r{0uz}; r < nums.size(); ++r) {
            curr *= nums[r];

            while (l < nums.size() && curr >= k) {
                curr /= nums[l++];
            }

            res += r - l + 1;
        }

        return res;
    }
};