class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l{};
        int r = nums.size() - 1;

        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) return {-1, -1};
        auto itx = std::upper_bound(nums.begin(), nums.end(), target);
        int first = it - nums.begin();
        int second = (itx - nums.begin()) - 1; 

        return {first, second};
    }
};