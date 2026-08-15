class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i{};
        int r = nums.size();

        while (r > i) {
            if (nums[i] == val) {
                swap(nums[i], nums[r-- - 1]);
            } else {
                ++i;
            }
        }

        return r;
    }
};