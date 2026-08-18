class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min{nums[0]}, max{nums[0]};
        int curr_min{nums[0]}, curr_max{nums[0]};

        for (auto i{1uz}; i < nums.size(); ++i) {
            auto tmp_min = curr_min;
            auto tmp_max = curr_max;

            curr_min = std::min({nums[i], nums[i] * tmp_min, nums[i] * tmp_max});
            curr_max = std::max({nums[i], nums[i] * tmp_max, nums[i] * tmp_min});

            min = std::min(min, curr_min);
            max = std::max(max, curr_max);
        }

        return max;
    }
};