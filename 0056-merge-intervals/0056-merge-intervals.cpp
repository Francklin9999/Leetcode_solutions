class Solution {
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[0] > b[0];
    }
};
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::priority_queue<
            vector<int>,
            vector<vector<int>>,
            cmp
        > pq;

        vector<vector<int>> results;

        for (auto i = 0uz; i < intervals.size(); ++i) {
            pq.push(intervals[i]);
        }

        auto last = pq.top();
        pq.pop();

        while (!pq.empty()) {
            auto top = pq.top();
            auto receive = helper(last, top);
            if (receive.size() > 1) {
                results.emplace_back(receive[0]);
                last = receive[1];
            } else {
                last = receive[0];
            }
            pq.pop();
        }

        results.emplace_back(last);
        return results;
    }

    vector<vector<int>> helper(vector<int>& a, vector<int>& b) {
        if (b[0] <= a[1]) {
            if (b[1] > a[1])
                return {{a[0], b[1]}};
            else
                return {a};
        } else {
            return {a, b};
        }
    }
};