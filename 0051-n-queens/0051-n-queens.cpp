class Solution {
void helper(int j, int n, vector<vector<string>>& res, vector<string>& curr, unordered_set<int>& col, unordered_set<int>& pos, unordered_set<int>& neg) {

    if (j == n) {
        res.push_back(curr);
        return;
    }

    string s(n - 1, '.');
    for (int i = 0; i < n; ++i) {
        if (col.count(i) || pos.count(j - i) || neg.count(j + i)) continue;
        col.insert(i);
        pos.insert(j - i);
        neg.insert(j + i);
        s.insert(i, "Q");
        curr.push_back(s);
        helper(j + 1, n, res, curr, col, pos, neg);
        curr.pop_back();
        col.erase(i);
        pos.erase(j - i);
        neg.erase(j + i);
        s.erase(i, 1);
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr;
        unordered_set<int> col;
        unordered_set<int> pos;
        unordered_set<int> neg;

        helper(0, n, res, curr, col, pos, neg);
        return res;
    }
};