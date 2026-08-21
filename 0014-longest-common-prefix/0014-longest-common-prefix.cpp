class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre{strs[0]};
        
        for (auto i{1uz}; i < strs.size(); ++i) {
            auto j{0uz};
            auto m = std::min(pre.size(), strs[i].size());
            for (; j < m; ++j) {
                if (pre[j] != strs[i][j]) break;
            }

            pre = pre.substr(0, j);
            if (pre == "") return "";
        }

        return pre;
    }
};