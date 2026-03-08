class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int min = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                min = std::min(nums[mid], min);
                r = mid - 1;
            }

        }

        return min;
    }
};