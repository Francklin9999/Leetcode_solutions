class Solution {
private:
    constexpr static int nei[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return std::get<0>(a) > std::get<0>(b);
        };

        std::priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> network;

        visited[0][0] = true;
        network.emplace(grid[0][0], 0, 0);
        int time{};

        while (1) {
            auto top = network.top();
            network.pop();
            time = std::max(time, std::get<0>(top));

            if (std::get<1>(top) == m - 1 && std::get<2>(top) == n - 1) break;

            for (const auto& k : nei) {
                auto x = std::get<1>(top) + k[0];
                auto y = std::get<2>(top) + k[1];

                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;

                visited[x][y] = true;
                network.emplace(grid[x][y], x, y);
            }
        }

        return time;
    }
};