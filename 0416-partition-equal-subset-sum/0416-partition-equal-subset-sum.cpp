class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        unordered_set<int> set;
        set.insert(0);
        int target = sum / 2;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> temp;
            for (int val : set) {
                if (val + nums[i] == target) return true;
                temp.insert(val);
                temp.insert(val + nums[i]);
            }
            set = temp;
        }

        return false;
    }
};