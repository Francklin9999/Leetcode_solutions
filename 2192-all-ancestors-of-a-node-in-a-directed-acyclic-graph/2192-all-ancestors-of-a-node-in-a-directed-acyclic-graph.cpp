class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> map;
        std::vector<int> indegree(n, 0);

        for (const auto& vec : edges) {
            map[vec[0]].push_back(vec[1]);
            ++indegree[vec[1]];
        }

        std::queue<int> q;
        for (std::size_t i{0}; i < n; ++i) {
            if (indegree[i] != 0) continue;
            q.push(i);
        }

        std::unordered_map<int, std::unordered_set<int>> ancestors;

        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            for (const auto& edge : map[i]) {
                if (--indegree[edge] == 0) q.push(edge);
                ancestors[edge].insert(ancestors[i].begin(), ancestors[i].end());
                ancestors[edge].insert(i);
            }
        }

        std::vector<std::vector<int>> res(n);

        for (auto& [key, value] : ancestors) {
            res[key] = {value.begin(), value.end()};
            sort(res[key].begin(), res[key].end());
        }

        return res;
    }
};