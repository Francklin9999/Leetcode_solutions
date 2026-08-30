class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res{};

        for (auto i{0uz}; i < nums.size(); ++i) {
            int curr{nums[i]};
            size_t r{i};
            while (curr < k) {
                ++res;
                ++r;
                if (r == nums.size()) break;
                curr *= nums[r];
            }
        }

        return res;          
    }
};