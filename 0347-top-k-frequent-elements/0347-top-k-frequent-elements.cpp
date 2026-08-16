class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int num : nums) map[num]++;


        auto cmp = [] (const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;

        for (auto [key, value] : map) {
            pq.emplace(pair<int, int>(key, value));

            if (pq.size() > k) pq.pop();
        }

        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};