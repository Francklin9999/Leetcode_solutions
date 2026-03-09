class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> perms;
        vector<bool> seen(nums.size(), false);

        helper(nums, results, perms, seen);
        return results;
    }

    void helper(vector<int>& nums, vector<vector<int>>& results, vector<int>& perms, vector<bool>& seen) {
        if (perms.size() >= nums.size()) {
            results.push_back(perms);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (seen[i]) continue;
            seen[i] = true;
            perms.push_back(nums[i]);
            helper(nums, results, perms, seen);
            perms.pop_back();
            seen[i] = false;
        }
    }
};