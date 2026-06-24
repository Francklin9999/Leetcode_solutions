class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int new_target = target - nums[i];
            if (map.contains(new_target)) {
                return {map[new_target], i};
            }

            map[nums[i]] = i;
        }

        return { };
    }
};