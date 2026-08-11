class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix{nums[0]};

        for (auto i = 1uz; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) break;
            prefix += nums[i];
        }

        unordered_set<int> set;
        for (auto i = 0uz; i < nums.size(); ++i) {
            set.insert(nums[i]);
        }

        int res = prefix;

        while (set.count(res++));

        return --res;
    }
};