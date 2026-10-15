class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto n = nums.size();

        auto max1 = nums[0] * nums[1] * nums[n - 1];
        auto max2 = nums[n - 3] * nums[n - 2] * nums[n - 1];

        return std::max(max1, max2);
    }
};