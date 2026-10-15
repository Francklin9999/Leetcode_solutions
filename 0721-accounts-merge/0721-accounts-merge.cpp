class Solution {
vector<int> parent;
vector<int> size;
private:
    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }

        return parent[a];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (size[b] > size[a]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map<string, int> account;

        parent.resize(accounts.size());
        size.resize(accounts.size(), 1);
        std::iota(parent.begin(), parent.end(), 0);

        for (std::size_t i{0}; i < accounts.size(); ++i) {
            for (std::size_t j{1}; j < accounts[i].size(); ++j) {
                const auto& email = accounts[i][j];

                if (auto it = account.find(email); it != account.end()) {
                    unite(parent[i], it->second);
                } else {
                    account[email] = i;
                }
            }
        }

        std::unordered_map<int, vector<string>> merged;

        for (auto& [key, value] : account) {
            merged[find(value)].push_back(std::move(key));
        }

        std::vector<std::vector<string>> res;
        res.reserve(merged.size());

        for (auto& [key, value] : merged) {
            sort(value.begin(), value.end());
            value.insert(value.begin(), accounts[key][0]);
            res.push_back(std::move(value));
        }

        return res;
    }
};