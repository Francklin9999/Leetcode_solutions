class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if(map.contains(num)) {
                return {map.at(num), i};
            }
            map.insert({nums[i], i});
        }

        return {};
    }
};