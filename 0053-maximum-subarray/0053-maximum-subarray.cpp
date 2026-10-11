class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr{nums[0]}, sub{nums[0]};

        for (auto i{1uz}; i < nums.size(); ++i) {
            if (curr < 0) curr = 0;

            curr += nums[i];

            sub = std::max(sub, curr);
        }

        return sub;
    }
};