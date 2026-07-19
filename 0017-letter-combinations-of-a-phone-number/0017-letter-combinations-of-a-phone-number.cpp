class Solution {
unordered_map<char, string> map{
    {'1', ""},
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string curr;
        dfs(res, curr, 0, digits);
        return res;
    }

    void dfs(vector<string>& res, string& curr, size_t i, string& digits) {
        if (i == digits.size()) {
            res.push_back(curr);
            return;
        }

        auto s = map[digits.at(i)];

        for (char c : s) {
            curr.push_back(c);
            dfs(res, curr, i + 1, digits);
            curr.pop_back();
        }
    }
};