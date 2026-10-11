class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) ++freq[num];

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; 
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;

        for (auto [key, value] : freq) {
            pq.emplace(key, value);
            if (pq.size() > k) pq.pop();
        }

        vector<int> res;
        res.reserve(k);

        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};