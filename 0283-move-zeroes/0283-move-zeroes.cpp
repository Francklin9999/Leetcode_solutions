class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z{}, n{}, len = nums.size();

        while (1) {
            while (z < len && nums[z] != 0) ++z;
            n = std::max(n, z + 1);
            while (n < len && nums[n] == 0) ++n;

            if (z == len || n == len) break;
            swap(nums[z], nums[n]);
        }
    }
};