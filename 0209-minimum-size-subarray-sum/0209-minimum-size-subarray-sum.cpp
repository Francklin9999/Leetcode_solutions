class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l{}, r{};
        int currSum{};
        int min = nums.size();
        bool good{};

        while (r < nums.size()) {
            currSum += nums[r];
            while (currSum >= target) {
                good = true;
                min = std::min(min, r - l + 1);
                currSum -= nums[l];
                l++;
            }
            r++;
        }

        return good ? min : 0;
    }
};