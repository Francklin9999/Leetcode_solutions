class Solution {
pair<int, int> calculate(const string& s) {
    int n{};

    for (auto i{0uz}; i < s.size(); ++i) {
        n += (s[i] - '0') & 1;
    }

    return {s.size() - n, n};
}
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        set<tuple<int, int, int>> cache;
        cache.insert({0, 0, 0});

        for (auto i{0uz}; i < strs.size(); ++i) {
            auto tmp = cache;
            auto c = calculate(strs[i]);

            for (auto& [z, o, count] : cache) {
                if (z + c.first <= m && o + c.second <= n) {
                    tmp.insert(tuple(z + c.first, o + c.second, count + 1));
                }
            }

            cache = std::move(tmp);
        }

        int ans{};

        for (auto& [z, o, count] : cache) {
            ans = std::max(ans, count);
        }

        return ans;
    }
};