class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(1, 0, k, n, curr, res);
        return res;
    }

    void dfs(int i, int sum, int k, int n, vector<int>& curr, vector<vector<int>>& res) {
        if (sum == n && static_cast<int>(curr.size()) == k) {
            res.push_back(curr);
            return;
        }

        if (static_cast<int>(curr.size()) >= k || sum > n || i > 9) {
            return;
        }

        curr.push_back(i);
        dfs(i + 1, sum + i, k, n, curr, res);
        curr.pop_back();
        dfs(i + 1, sum, k, n, curr, res);
    }
};