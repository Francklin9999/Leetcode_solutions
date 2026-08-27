class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int arr[3] = {1, 0, 1};

        for (int obj : obstacles) {
            if (obj) arr[obj - 1] = INT_MAX;

            int best = std::min({arr[0], arr[1], arr[2]});

            for (auto i{0uz}; i < 3; ++i) {
                if (i == obj - 1) continue;
                arr[i] = std::min(arr[i], best + 1);
            }
        }

        return std::min({arr[0], arr[1], arr[2]});
    }
};