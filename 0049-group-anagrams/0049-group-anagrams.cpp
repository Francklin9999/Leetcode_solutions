class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (auto i{0uz}; i < strs.size(); ++i) {
            auto cp = strs[i];
            sort(cp.begin(), cp.end());
            groups[cp].emplace_back(std::move(strs[i]));
        }

        std::vector<std::vector<string>> group;

        for (auto [_, val] : groups) {
            group.emplace_back(std::move(val));
        }

        return group;
    }
};