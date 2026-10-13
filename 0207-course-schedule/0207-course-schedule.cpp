class Solution {
bool dfs(std::unordered_map<int, vector<int>>& courses,
        std::unordered_set<int>& seen,
        std::unordered_set<int>& path,
        int course) {
            if (path.contains(course)) return false;
            if (seen.contains(course)) return true;

            path.insert(course);
            for (auto& pre : courses[course]) {
                if (!dfs(courses, seen, path, pre)) return false;
            }
            path.erase(course);

            seen.insert(course);
            return true;
        }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> courses;

        for (auto& pre : prerequisites) {
            courses[pre[0]].push_back(pre[1]);
        }

        std::unordered_set<int> seen;
        std::unordered_set<int> path;

        for (auto [course, _] : courses) {
            if (!dfs(courses, seen, path, course)) return false;
        }

        return true;
    }
};