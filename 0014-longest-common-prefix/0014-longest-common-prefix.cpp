class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto prefix{strs[0]};

        for (auto i{1uz}; i < strs.size(); ++i) {
            int l{};
            int min = std::min(prefix.size(), strs[i].size());
            while (l < min && prefix[l] == strs[i][l]) l++;
            prefix = prefix.substr(0, l);
        }

        return prefix;
    }
};