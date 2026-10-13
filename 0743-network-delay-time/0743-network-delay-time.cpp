class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::unordered_map<int, vector<vector<int>>> edges;

        for (const auto& time : times) {
            edges[time[0]].emplace_back(time);
        }

        std::unordered_set<int> visited;

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        };

        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> network;
        int time{};

        for (const auto& value : edges[k]) {
            network.emplace(value);
        }

        visited.insert(k);
        while (visited.size() < n && !network.empty()) {
            auto top = network.top();
            network.pop();

            if (visited.find(top[1]) == visited.end()) {
                visited.insert(top[1]);
                time = std::max(time, top[2]);

                for (auto value : edges[top[1]]) {
                    value[2] += top[2];
                    network.emplace(value);
                }
            }
        }

        return visited.size() == n ? time : -1;

    }
};