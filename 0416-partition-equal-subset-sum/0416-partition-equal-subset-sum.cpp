class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        unordered_set<int> sums;
        sums.insert(nums[nums.size() - 1]);

        for (auto i{nums.size() - 1}; i-- > 0; ) {
            unordered_set<int> tmp(sums.begin(), sums.end());
            if (sums.count(target - nums[i])) return true;

            for (int s : sums) {
                tmp.insert(nums[i] + s);
            }

            sums = tmp;
        }

        return sums.count(target);
    }
};