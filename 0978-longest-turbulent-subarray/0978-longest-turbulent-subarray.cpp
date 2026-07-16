class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int max{};
        int curr{1};
        bool greater{};
        bool hasSeen{false};

        for (auto i = 1uz; i < arr.size(); ++i) {
            max = std::max(max, curr);
            if (arr[i] > arr[ i - 1]) {
                if (!hasSeen || !greater) curr++;
                else curr = 2;
                hasSeen = true;
                greater = true;
            } else if (arr[i] < arr[ i - 1]) {
                if  (!hasSeen || greater) curr++;
                else curr = 2;
                hasSeen = true;
                greater = false;
            } else {
                curr = 1;
            }
        }

        return std::max(max, curr);
    }
};