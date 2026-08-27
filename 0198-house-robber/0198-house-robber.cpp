class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1{}, prev2{};

        for (int num : nums) {
            auto tmp = prev1;
            prev1 = std::max(prev1, prev2 + num);
            prev2 = tmp;
        }

        return std::max(prev1, prev2);
    }
};