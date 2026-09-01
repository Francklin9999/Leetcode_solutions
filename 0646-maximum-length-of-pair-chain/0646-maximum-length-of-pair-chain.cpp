class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end());


        for (auto i{pairs.size()}; i-- > 0; ) {
            for (auto j{i + 1}; j < pairs.size(); ++j) {
                if (pairs[i][1] < pairs[j][0])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        
        return *std::max_element(dp.begin(), dp.end());
    }
};