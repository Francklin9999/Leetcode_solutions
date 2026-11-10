class Solution {
private:
    int helper(vector<int>& nums, size_t start, size_t end) {
        int prev1{}, prev2{};

        for (auto i{start}; i < end; ++i) {
            int tmp = prev1;
            prev1 = std::max(prev1, prev2 + nums[i]);
            prev2 = tmp;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        return std::max({
            nums[0],
            helper(nums, 0, nums.size() - 1),
            helper(nums, 1, nums.size())
        });
    }
};