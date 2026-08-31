class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 1);

        for (auto i{nums.size()}; i-- > 0; ) {
            for (auto j{i + 1}; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};