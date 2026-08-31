class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res{nums[0]}, curr{}, l{};

        for (auto r{0uz}; r < nums.size(); ++r) {
            curr += nums[r];
            
            res = std::max(res, curr);

            if (curr < 0) curr = 0;
        }

        return res;
    }
};