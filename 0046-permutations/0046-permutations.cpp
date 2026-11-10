class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, size_t idx) {
        if (idx >= nums.size()) {
            res.push_back(curr);
            return;
        }

        for (auto i{0}; i <= curr.size(); ++i) {
            curr.insert(curr.begin() + i, nums[idx]);
            dfs(nums, res, curr, idx + 1);
            curr.erase(curr.begin() + i);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        curr.reserve(nums.size());

        dfs(nums, res, curr, 0);
        return res;
    }
};