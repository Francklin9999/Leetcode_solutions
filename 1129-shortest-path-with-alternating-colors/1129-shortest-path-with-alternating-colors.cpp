class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        std::unordered_map<int, std::vector<int>> red;
        std::unordered_map<int, std::vector<int>> blue;

        for (const auto& vec : redEdges) {
            red[vec[0]].push_back(vec[1]);
        }

        for (const auto& vec : blueEdges) {
            blue[vec[0]].push_back(vec[1]);
        }

        std::queue<pair<int, bool>> q;

        q.emplace(0, true);
        q.emplace(0, false);

        vector<int> res(n, INT_MAX);
        res[0] = 0;

        std::unordered_set<int> r;
        std::unordered_set<int> b;

        r.insert(0);
        b.insert(0);

        int path{1};

        while (!q.empty()) {
            auto sz = q.size();

            for (std::size_t idx{0}; idx < sz; ++idx) {
                auto front = q.front();
                q.pop();

                if (front.second) {
                    for (const auto& nei : red[front.first]) {
                        if (b.contains(nei)) continue;
                        b.insert(nei);
                        q.emplace(nei, false);
                        res[nei] = std::min(res[nei], path);
                    }
                } else {
                    for (const auto& nei : blue[front.first]) {
                        if (r.contains(nei)) continue;
                        r.insert(nei);
                        q.emplace(nei, true);
                        res[nei] = std::min(res[nei], path);
                    }
                }
            }

            ++path;
        }

        for (std::size_t idx{1}; idx < res.size(); ++idx) {
            if (res[idx] == INT_MAX) res[idx] = -1;
        }

        return res;
    }
};