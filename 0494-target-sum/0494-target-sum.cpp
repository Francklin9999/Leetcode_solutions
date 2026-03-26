class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        map[nums[0]]++;
        map[-nums[0]]++;
        int ways = 0;

        for (int i = 1; i < nums.size(); i++) {
            unordered_map<int, int> temp;
            for (const auto& it : map) {
                temp[it.first + nums[i]] += it.second;
                temp[it.first - nums[i]] += it.second;
            }
            map = temp;
        }

        for (const auto& it : map) {
            if (it.first == target) ways += it.second;
        }

        return ways;
    }
};