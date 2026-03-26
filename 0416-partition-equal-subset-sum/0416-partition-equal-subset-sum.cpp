class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        unordered_set<int> set;
        set.insert(0);

        for (int num : nums) {
            unordered_set<int> temp;
            for (int val : set) {
                if (val + num == sum / 2) return true;
                temp.insert(val);
                temp.insert(val + num);
            }
            set = temp;
        }

        return false;
    }
};