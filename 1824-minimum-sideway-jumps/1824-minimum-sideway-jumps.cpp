class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int lanes[] = {1, 0, 1};

        for (int obs : obstacles) {
            if (obs) lanes[obs - 1] = INT_MAX;

            auto best = std::min({lanes[0], lanes[1], lanes[2]});

            for (int i{0}; i < 3; ++i) {
                if (obs - 1 == i) continue;

                lanes[i] = std::min(lanes[i], best + 1);
            }
        }

        return std::min({lanes[0], lanes[1], lanes[2]});
    }
};