class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return std::max(nums[0], 0);
        }
        return std::max(
            helper(nums, 0, nums.size() - 1),
            helper(nums, 1, nums.size())
        );
    }

    int helper(vector<int>& nums, int i, int j) {
        int prev1{}, prev2{};

        for (auto k = i; k < j; ++k) {
            int tmp = prev1;
            prev1 = std::max(prev1, prev2 + nums[k]);
            prev2 = tmp;
        }

        return std::max(prev1, prev2);
    }
};