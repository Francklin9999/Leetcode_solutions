class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> rob1(nums.begin() + 1, nums.end());
        vector<int> rob2(nums.begin(), nums.end() - 1);
        return (
            std::max(nums[0],
                std::max(
                    helper(rob1),
                    helper(rob2)
                )
            )
        );
    }

    int helper(vector<int>& nums) {
        int prev0 = 0;
        int prev1 = 0;
        int temp;

        for (int i = 0; i < nums.size(); ++i) {
            temp = std::max(prev0 + nums[i], prev1);
            prev0 = prev1;
            prev1 = temp;
        }

        return std::max(prev0, prev1);
    }
};