class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int cache[2] = {INT_MIN, INT_MIN};

        for (auto i{nums.size()}; i-- > 0; ) {
            if (nums[i] >= cache[1]) {
                cache[1] = nums[i];
            } else if (nums[i] >= cache[0]) {
                cache[0] = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};