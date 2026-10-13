class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        if (start_node == end_node) return 1.0;

        std::vector<std::vector<pair<int, double>>> map(n);

        for (std::size_t i{0}; i < edges.size(); ++i) {
            map[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            map[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        auto cmp = [](const auto& a, const auto& b) {
            return a.second < b.second;
        };

        std::priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(cmp)> network;

        for (const auto& edge : map[start_node]) {
            network.emplace(edge);
        }

        std::unordered_set<int> visited;
        visited.insert(start_node);

        while (!network.empty()) {
            auto [dest, prob] = network.top();
            network.pop();

            if (visited.contains(dest)) continue;
            if (dest == end_node) return prob;

            visited.insert(dest);

            for (auto edge : map[dest]) {
                if (visited.contains(edge.first)) continue;
                edge.second *= prob;
                network.emplace(edge);
            }
        }

        return 0.0;
    }
};