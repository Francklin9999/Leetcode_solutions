class Solution {
private:
    void dfs(int n, int k, int idx, vector<vector<int>>& res, vector<int>& curr) {
        if (idx > n) return;
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }

        for (int i{idx + 1}; i <= n; ++i) {
            curr.push_back(i);
            dfs(n, k, i, res, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;

        dfs(n, k, 0, res, curr);
        return res;
    }
};