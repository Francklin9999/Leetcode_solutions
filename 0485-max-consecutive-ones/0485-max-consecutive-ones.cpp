class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxC = 0;
        int localMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) localMax++;
            else {
                maxC = std::max(maxC, localMax);
                localMax = 0;
            }
        }

        return std::max(maxC, localMax);
    }
};