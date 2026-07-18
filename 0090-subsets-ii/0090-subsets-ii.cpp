class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, 0, res, curr);
        return res;
    }

    void dfs(vector<int>& nums, size_t i, vector<vector<int>>& res, vector<int>& curr) {
        if (i >= nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, i + 1, res, curr);
        curr.pop_back();
        while(i >= 0 && i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        dfs(nums, i + 1, res, curr);
    }
};