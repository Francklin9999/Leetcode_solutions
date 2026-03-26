class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        map[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> temp;
            for (const auto& it : map) {
                temp[it.first + nums[i]] += it.second;
                temp[it.first - nums[i]] += it.second;
            }
            map = temp;
        }

        return map[target];
    }
};