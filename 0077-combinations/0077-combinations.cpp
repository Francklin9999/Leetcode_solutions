class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(1, n, k, curr, res);
        return res;
    }

    void dfs(int idx, int n, int k, vector<int>& curr, vector<vector<int>>& res) {
        if (static_cast<int>(curr.size()) == k) {
            res.push_back(curr);
            return;
        }
        if (idx > n) return;

        curr.push_back(idx);
        dfs(idx + 1, n, k, curr, res);
        curr.pop_back();
        dfs(idx + 1, n, k, curr, res);
    }
};