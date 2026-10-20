class Solution {
private:
    std::pair<int, bool> dfs(std::unordered_map<int, std::vector<int>>& ajd, int edge, std::vector<bool>& hasApple, std::unordered_set<int>& visited) {
        int time{};
        bool valid{false};
        for (const auto& e : ajd[edge]) {
            if (visited.count(e)) continue;
            visited.insert(e);
            auto [val, apple] = dfs(ajd, e, hasApple, visited);
            if (apple) {
                time += val;
                valid = true;
            }
        }

        return std::make_pair(time + 1, hasApple[edge] | valid);
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        std::unordered_map<int, std::vector<int>> ajd;
        std::unordered_set<int> visited;
        visited.insert(0);

        for (const auto& e : edges) {
            ajd[e[0]].push_back(e[1]);
            ajd[e[1]].push_back(e[0]);
        }

        int time{};
        for (const auto& e : ajd[0]) {
            visited.insert(e);
            auto [val, apple] = dfs(ajd, e, hasApple, visited);
            if (apple) time += val;
        }

        return time * 2;
    }
};