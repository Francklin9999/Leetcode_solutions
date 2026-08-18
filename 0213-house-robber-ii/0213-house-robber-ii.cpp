class Solution {
int helper(vector<int>& nums, int l, int r) {
    int prev1{}, prev2{};

    for (auto i{l}; i < r; ++i) {
        auto tmp = prev1;
        prev1 = std::max(prev1, prev2 + nums[i]);
        prev2 = tmp;
    }

    return prev1;
}

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return std::max(helper(nums, 1, nums.size()), helper(nums, 0, nums.size() - 1));
    }
};