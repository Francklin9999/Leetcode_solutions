class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = *std::max_element(nums.begin(), nums.end());
        
        vector<int> freq(m + 1, 0);
        vector<int> dp(m + 1);

        for (int num : nums) ++freq[num];

        dp[0] = 0;
        dp[1] = freq[1];

        int res{};

        for (int i{2}; i <= m; ++i) {
            dp[i] = std::max(
                dp[i - 1],
                dp[i - 2] + i * freq[i]
            );
        }

        return dp[m];
    }
};