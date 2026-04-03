class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minL = INT_MAX;
        int l = 0;
        int r = 0;
        int currCount = 0;

        while (r < nums.size()) {
            currCount += nums[r];
            while (currCount >= target) {
                minL = std::min(minL, r - l + 1);
                currCount -= nums[l];
                l++;
            }

            r++;
        }

        return minL == INT_MAX ? 0 : minL;
    }
};