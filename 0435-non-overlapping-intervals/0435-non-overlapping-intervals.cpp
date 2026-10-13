class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int number_to_erase{0};

        for (auto i{1uz}; i < intervals.size(); ++i) {
            if (intervals[i].front() < intervals[i - 1].back()) {
                ++number_to_erase;
                intervals[i].back() = std::min(intervals[i].back(), intervals[i - 1].back());
            }
        }

        return number_to_erase;
    }
};