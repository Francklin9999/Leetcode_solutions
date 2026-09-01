class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size(), {1, 1});

        for (auto i{nums.size()}; i-- > 0; ) {
            for (auto j{i + 1}; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    if (dp[j].first + 1 > dp[i].first) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    } else if (dp[j].first + 1 == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
        }

        int len{}, count{};

        for (auto [l, c] : dp) {
            if (l > len) {
                len = l;
                count = c;
            } else if (l == len) {
                count += c;
            }
        }

        return count;
    }
};