class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> cache;

        for (auto i{0uz}; i < nums.size(); ++i) {
            auto it = cache.find(target - nums[i]);
            if (it != cache.end()) return {static_cast<int>(it->second), static_cast<int>(i)};
            cache[nums[i]] = i;
        }

        return {-1, -1};
    }
};