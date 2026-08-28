class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> freq;

        for (int num : nums) ++freq[num];

        int m = *std::max_element(nums.begin(), nums.end());

        vector<int> dp(m + 1);
        dp[0] = 0;

        int res{};

        for (auto i{1uz}; i < dp.size(); ++i) {
            if (i > 1) dp[i] = dp[i - 2];
            
            auto it = freq.find(i);
            if (it != freq.end()) dp[i] += (it->first * it->second);

            dp[i] = std::max(dp[i], dp[i - 1]);

            res = std::max(res, dp[i]);
        }

        return res;
    }
};