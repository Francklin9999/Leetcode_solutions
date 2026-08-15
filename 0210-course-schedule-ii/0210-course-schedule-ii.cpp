class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;

        for (int i{}; i < numCourses; ++i) {
            map.insert({i, {}});
        }

        for (auto i{0uz}; i < prerequisites.size(); ++i) {
            map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set<int> visited;
        unordered_set<int> path;
        vector<int> out;

        for (auto [pre, _] : map) {
            if(!dfs(map, visited, path, out, pre)) return {};
        }

        return out;
    }

    bool dfs(unordered_map<int, vector<int>>& map, unordered_set<int>& visited, unordered_set<int>& path, vector<int>& out, int curr) {
        if (path.count(curr)) return false;
        if (visited.count(curr)) return true;

        path.insert(curr);

        for (auto i{0uz}; i < map[curr].size(); ++i) {
            if (!dfs(map, visited, path, out, map[curr][i])) return false;
        }

        path.erase(curr);
        out.push_back(curr);
        visited.insert(curr);

        return true;
    }
};