class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int prefix{};
        int total{};
        map[0] = 1;

        for (auto i{0uz}; i < nums.size(); ++i) {
            prefix += nums[i];

            total += map[prefix - k];

            map[prefix]++;
        }

        return total;
    }
};