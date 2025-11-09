#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            int target2 = target - nums[i];
            if(map.find(target2) != map.end()) {
                return {map[target2], i};
            }
            map.insert({nums[i], i});
        }

        return {};
        
    }
};