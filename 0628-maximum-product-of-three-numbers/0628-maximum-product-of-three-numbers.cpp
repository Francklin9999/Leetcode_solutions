class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::vector<int> max{nums[0], nums[1], nums[2]};
        std::vector<int> min{nums[0], nums[1], nums[2]};

        for (std::size_t i{3}; i < nums.size(); ++i) {
            max.push_back(nums[i]);
            min.push_back(nums[i]);

            std::sort(max.begin(), max.end(), std::greater<int>());
            std::sort(min.begin(), min.end());

            max.pop_back();
            min.pop_back();
        }

        std::sort(max.begin(), max.end(), std::greater<int>());
        std::sort(min.begin(), min.end());

        return std::max(max[0] * max[1] * max[2], min[0] * min[1] * max[0]);
    }
};