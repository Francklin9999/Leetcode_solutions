class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1{}, prev2{};
        for (auto i{0uz}; i < nums.size(); ++i) {
            auto tmp = prev1;
            prev1 = std::max(prev1, prev2 + nums[i]);
            prev2 = tmp;
        }

        return std::max(prev1, prev2);
    }
};