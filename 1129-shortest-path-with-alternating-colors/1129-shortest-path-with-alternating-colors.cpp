class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        std::unordered_map<int, std::vector<int>> red;
        std::unordered_map<int, std::vector<int>> blue;

        for (const auto& vec : redEdges) red[vec[0]].push_back(vec[1]);
        for (const auto& vec : blueEdges) blue[vec[0]].push_back(vec[1]);

        std::queue<std::pair<int, bool>> q;

        q.emplace(0, true);
        q.emplace(0, false);

        std::vector<int> res(n, -1);
        std::vector<std::vector<bool>> visited(2, std::vector<bool>(n, false));

        visited[0][0] = true;
        visited[1][0] = true;

        int path{};

        while (!q.empty()) {
            auto sz = q.size();
            for (std::size_t i{0}; i < sz; ++i) {
                auto [edge, isRed] = q.front();
                q.pop();

                if (res[edge] == -1) res[edge] = path;

                auto& map = isRed ? blue : red;

                for (const auto& e : map[edge]) {
                    if (visited[isRed][e]) continue;
                    visited[isRed][e] = true;
                    q.emplace(e, !isRed);
                }
            }

            ++path;
        }

        return res;
    }
};