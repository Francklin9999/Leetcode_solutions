class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max{};

        for (std::size_t i{0}; i < nums.size() - 1; ++i) {
            max = std::max(max, nums[i] + static_cast<int>(i));
            if (max <= i) return false;
        }

        return true;
    }
};