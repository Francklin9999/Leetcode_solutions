class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](std::pair<int,int> a, std::pair<int,int> b) {
            return b.first < a.first;
        };

        std::priority_queue<
            std::pair<int,int>,
            std::vector<std::pair<int,int>>,
            decltype(cmp)
        > pq(cmp);

        for (int i = 0; i < points.size(); ++i) {
            int distance = 
                ((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            pq.push(pair(distance, i));
        }

        vector<vector<int>> res;

        for (int _ = 0; _ < k; ++_) {
            auto curr = pq.top();
            res.push_back(points[curr.second]);
            pq.pop();
        }

        return res;
    }
};