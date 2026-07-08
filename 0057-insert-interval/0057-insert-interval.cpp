class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto i = 0uz;
        vector<vector<int>> result;

        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            result.push_back(intervals[i]);
            i++;
        }

        int first{newInterval[0]};
        int second{newInterval[1]};
        while (i < intervals.size() && second >= intervals[i][0]) {
            first = std::min(first, intervals[i][0]);
            second = std::max(second, intervals[i][1]);
            i++;
            if (i < intervals.size() && second < intervals[i][0]) break;
        }

        result.push_back({first, second});
        
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};