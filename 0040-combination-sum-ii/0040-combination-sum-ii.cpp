class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, 0, candidates, res, curr, target);
        return res;
    }

    void dfs(int idx, int sum, vector<int>& candidates, vector<vector<int>>& res, vector<int>& curr, int target) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }
        
        if (idx >= static_cast<int>(candidates.size()) || sum > target) return;

        curr.push_back(candidates[idx]);
        dfs(idx + 1, sum + candidates[idx], candidates, res, curr, target);
        curr.pop_back();
        while (idx >= 0 && idx < candidates.size() - 1 && candidates[idx] == candidates[idx + 1]) idx++;
        dfs(idx + 1, sum, candidates, res, curr, target);
    }
};