class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i{target}; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }

            if (dp[target]) return true;
        }

        return false;
    }
};