class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (auto i{nums.size()}; i-- > 0; ) {
            for (auto j{i}; j-- > 0; ) {
                if (nums[i] > nums[j]) {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};