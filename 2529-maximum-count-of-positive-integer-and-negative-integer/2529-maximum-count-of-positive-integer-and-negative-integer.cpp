class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto it1 = std::lower_bound(nums.begin(), nums.end(), 0);
        auto it2 = std::upper_bound(nums.begin(), nums.end(), 0);

        return std::max(it1 - nums.begin(), nums.end() - it2);
    }
};