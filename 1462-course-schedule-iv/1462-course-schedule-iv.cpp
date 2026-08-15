class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>> vec(numCourses);
        vector<int> cache(numCourses, 0);

        for (auto i{0uz}; i < prerequisites.size(); ++i) {
            vec[prerequisites[i][0]].insert(prerequisites[i][1]);
        }
        
        for (auto i{0uz}; i < vec.size(); ++i) {
            auto s = dfs(vec, cache, i);
            vec[i].insert(s.begin(), s.end());
        }

        vector<bool> res;
        for (auto i{0uz}; i < queries.size(); ++i) {
            res.push_back(static_cast<bool>(vec[queries[i][0]].count(queries[i][1])));
        }

        return res;
    }

    unordered_set<int>& dfs(vector<unordered_set<int>>& vec, vector<int>& cache, int course) {
        if (cache[course]) return vec[course];

        for (auto c : vec[course]) {
            auto s = dfs(vec, cache, c);
            vec[course].insert(s.begin(), s.end());
        }

        cache[course] = 1;
        return vec[course];
    }
};