class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        auto cmp = [] (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap;

        unordered_map<int, vector<pair<int, int>>> map;

        for (auto i = 0uz; i < times.size(); ++i) {
            map[times[i][0]].emplace_back(times[i][1], times[i][2]);
        }

        set<int> seen;
        int total{};

        minHeap.emplace(k, 0);

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            if (seen.find(curr.first) != seen.end()) continue;
            seen.insert(curr.first);
            total = std::max(total, curr.second);
            for (auto& e : map[curr.first]) {
                if (seen.find(e.first) != seen.end()) continue;
                minHeap.emplace(e.first, e.second + curr.second);
            }
        }

        return seen.size() == n ? total : -1;
    }
};