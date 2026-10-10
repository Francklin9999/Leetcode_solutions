class Solution {
private:
    void helper(vector<string>& res, string& curr, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(curr);
            return;
        }
        if (left > right) return;

        if (left) {
            curr.push_back('(');
            helper(res, curr, left - 1, right);
            curr.pop_back();
        }

        if (right) {
            curr.push_back(')');
            helper(res, curr, left, right - 1);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr{};
        helper(res, curr, n, n);
        return res;
    }
};