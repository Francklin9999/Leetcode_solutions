class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

        for (auto& s : strs) {
            auto cp = s;
            sort(cp.begin(), cp.end());
            group[cp].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [_, value] : group) {
            res.push_back(value);
        }

        return res;
    }
};