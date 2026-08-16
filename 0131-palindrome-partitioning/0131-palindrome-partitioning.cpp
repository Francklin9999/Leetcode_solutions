class Solution {
bool isPalindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }

    return true;
}

void helper(vector<vector<string>>& res, vector<string>& curr, string& s, size_t i) {
    if (i == s.size()) {
        res.push_back(curr);
        return;
    }
    
    for (auto j{i}; j < s.size(); ++j) {
        if (isPalindrome(s, i, j)) {
            curr.push_back(s.substr(i, j - i + 1));
            helper(res, curr, s, j + 1);
            curr.pop_back();
        }
    }
}

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        helper(res, out, s, 0);
        return res;
    }
};