class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& vectorA, const vector<int>& vectorB) {
            if (vectorA[0] == vectorB[0]) {
                return vectorA[1] < vectorB[1];
            }

            return vectorA[0] < vectorB[0];
        });

        int second{intervals[0][1]};
        int count{};

        for (auto i = 1uz; i < intervals.size(); ++i) {
            if (second > intervals[i][0]) {
                ++count;
                if (second > intervals[i][1]) {
                    second = intervals[i][1];
                }
                continue;
            }

            second = intervals[i][1];
        }


        return count;
    }
};