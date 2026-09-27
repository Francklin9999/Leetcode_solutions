class Solution {
constexpr static std::array<std::array<int, 2>, 4> nei = {{
    {{0, 1}}, 
    {{1, 0}}, 
    {{0, -1}}, 
    {{-1, 0}}
}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<pair<int, int>> queue;

        for (auto i{0uz}; i < grid.size(); ++i) {
            for (auto j{0uz}; j < grid[0].size(); ++j) {
                if (grid[i][j] != 2) continue;
                queue.emplace(i, j);
            }
        }

        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop();
            for (auto [k, z] : nei) {
                auto x = k + top.first;
                auto y = z + top.second;

                if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) continue;
                grid[x][y] = grid[top.first][top.second] + 1;
                queue.emplace(x, y);
            }
        }

        int res{};
        for (auto i{0uz}; i < grid.size(); ++i) {
            for (auto j{0uz}; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) return -1;
                res = std::max(res, grid[i][j]);
            }
        }

        return res == 0 ? 0 : res - 2;
    }
};