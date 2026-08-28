class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        sort(nums.begin(), nums.end());

        int res{INT_MAX};
        for (std::size_t l{0}, r = k - 1; r < nums.size(); ++l, ++r) {
            res = std::min(res, nums[r] - nums[l]);
        }

        return res;
    }
};