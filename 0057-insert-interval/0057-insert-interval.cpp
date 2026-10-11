class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        vector<vector<int>> res;
        bool merged{false};

        for (auto& interval : intervals) {
            if (!merged) {
                if (newInterval[1] < interval[0]) {
                    res.push_back(newInterval);
                    merged = true;
                } else if (newInterval[0] <= interval[1]) {
                    interval.front() = std::min(interval.front(), newInterval.front());
                    interval.back() = std::max(interval.back(), newInterval.back());
                    merged = true;
                }
            }

            if (!res.empty() && interval.front() <= res.back().back()) {
                res.back().back() = std::max(res.back().back(), interval.back());
            } else {
                res.push_back(std::move(interval));
            }
        }

        if (!merged) res.push_back(std::move(newInterval));

        return res;
    }
};