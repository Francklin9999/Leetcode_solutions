class Solution {
public:
    int findMin(vector<int>& nums) {
        int l{}, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= nums[l]) {
                if (nums[l] > nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};