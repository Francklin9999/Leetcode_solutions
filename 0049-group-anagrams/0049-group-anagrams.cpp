class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (auto i{0uz}; i < strs.size(); ++i) {
            auto tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            groups[tmp].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for (auto& [_, value] : groups) {
            res.push_back(value);
        }

        return res;
    }
};