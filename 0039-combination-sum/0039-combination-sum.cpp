class Solution {
void helper(vector<vector<int>>& res, vector<int>& candidates, vector<int>& curr, int i, int sum, int target){
    if (sum > target) return;
    if (sum == target) {
        res.push_back(curr);
        return;
    }

    if (i == candidates.size()) return;

    curr.push_back(candidates[i]);
    helper(res, candidates, curr, i, sum + candidates[i], target);
    curr.pop_back();
    helper(res, candidates, curr, i + 1, sum, target);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(res, candidates, curr, 0, 0, target);
        return res;
    }
};