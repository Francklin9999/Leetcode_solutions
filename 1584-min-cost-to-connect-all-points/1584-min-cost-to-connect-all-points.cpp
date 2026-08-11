class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<int, vector<pair<int, int>>> map;

        for (auto i = 0uz; i < points.size(); ++i) {
            for (auto j = i; j < points.size(); ++j) {
                auto dist = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                map[i].emplace_back(dist, j);
                map[j].emplace_back(dist, i);
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> set;
        int res{};
        pq.emplace(0, 0);

        while (set.size() < points.size()) {
            auto top = pq.top();
            pq.pop();
            
            if (set.count(top.second)) continue;
            set.insert(top.second);

            res += top.first;

            for (auto& nei : map[top.second]) {
                pq.emplace(nei.first, nei.second);
            }
        }

        return res;
    }
};