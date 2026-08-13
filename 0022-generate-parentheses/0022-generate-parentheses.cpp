class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr{};
        helper(res, curr, n, n);
        return res;
    }

    void helper(vector<string>& out, string& curr, int left, int right) {
        if (right < left) return;

        if (left == 0 && right == 0) {
            out.push_back(curr);
            return;
        }

        if (left > 0) {
            curr.push_back('(');
            helper(out, curr, left - 1, right);
            curr.pop_back();
        }

        if (right > 0) {
            curr.push_back(')');
            helper(out, curr, left, right - 1);
            curr.pop_back();
        }
    }
};