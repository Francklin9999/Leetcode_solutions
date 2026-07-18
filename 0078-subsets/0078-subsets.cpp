class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, 0, res, curr);
        return res;
    }

    void dfs(vector<int>& nums, size_t i, vector<vector<int>>& res, vector<int>& curr) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, i + 1, res, curr);
        curr.pop_back();
        dfs(nums, i + 1, res, curr);
    }
};