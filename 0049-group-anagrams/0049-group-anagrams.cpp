class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

        for (auto i{0uz}; i < strs.size(); ++i) {
            auto s = strs[i];

            sort(s.begin(), s.end());

            group[s].push_back(strs[i]);
        }

        vector<vector<string>> res;
        res.reserve(group.size());

        for (auto& [key, value] : group) {
            res.push_back(value);
        }

        return res;
    }
};