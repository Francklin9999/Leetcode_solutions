class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = INT_MIN;
        double localSum = INT_MIN;

        for (int num : nums) {
            if (localSum < 0) {
                localSum = num;
            } else {
                localSum += num;
            }

            maxSub = std::max(maxSub, static_cast<int>(localSum));
        }

        return maxSub;
    }
};