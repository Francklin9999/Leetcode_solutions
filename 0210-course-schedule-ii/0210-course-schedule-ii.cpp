class Solution {
private:
    bool dfs(std::unordered_map<int, vector<int>>& courses,
            std::unordered_set<int>& visited,
            std::unordered_set<int>& path,
            vector<int>& order,
            int course) {
                if (path.contains(course)) return false;
                if (visited.contains(course)) return true;

                path.insert(course);

                for (auto nei : courses[course]) {
                    if (!dfs(courses, visited, path, order, nei)) return false;
                }

                path.erase(course);
                order.push_back(course);
                visited.insert(course);
                return true;
            }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> courses;

        for (const auto& pre : prerequisites) {
            courses[pre[0]].push_back(pre[1]);
        }

        std::unordered_set<int> visited;
        std::unordered_set<int> path;
        vector<int> order;
        order.reserve(numCourses);

        for (std::size_t i{0}; i < numCourses; ++i) {
            if (!dfs(courses, visited, path, order, i)) return {};
        }

        return order;
    }
};