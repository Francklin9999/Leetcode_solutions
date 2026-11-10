class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, size_t idx) {
        if (idx >= nums.size()) {
            res.push_back(curr);
            return;
        }

        dfs(nums, res, curr, idx + 1);
        curr.push_back(nums[idx]);
        dfs(nums, res, curr, idx + 1);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        dfs(nums, res, curr, 0);
        return res;
    }
};