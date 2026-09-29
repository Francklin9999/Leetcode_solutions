class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for (auto s : strs) {
            auto s2 = s;
            sort(s2.begin(), s2.end());
            group[s2].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(group.size());
        for (auto [_, value] : group) {
            res.push_back(value);
        }

        return res;
    }
};