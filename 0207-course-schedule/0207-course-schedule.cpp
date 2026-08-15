class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;

        for (auto i{0uz}; i < prerequisites.size(); ++i) {
            map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set<int> visited;
        unordered_set<int> path;

        for (auto [pre, _] : map) {
            if (!dfs(map, visited, path, pre)) return false;
        }

        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& map, unordered_set<int>& visited, unordered_set<int>& path, int curr) {
        if (path.count(curr)) return false;
        if (visited.count(curr)) return true;
        path.insert(curr);
        visited.insert(curr);

        for (auto i{0uz}; i < map[curr].size(); ++i) {
            if (!dfs(map, visited, path, map[curr][i])) return false;
        }
        
        path.erase(curr);

        return true;
    }
};