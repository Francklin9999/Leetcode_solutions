class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (auto i{0uz}; i < nums.size(); ++i) {
            if (auto it = seen.find(target - nums[i]); it != seen.end()) return {it->second, static_cast<int>(i)};
            seen[nums[i]] = i;
        }

        return { };
    }
};