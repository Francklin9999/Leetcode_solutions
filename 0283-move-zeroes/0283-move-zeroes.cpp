class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z{};
        int n{};
        int len{static_cast<int>(nums.size())};

        while (1) {
            while (z < len && nums[z] != 0) ++z;
            n = std::max(n, z + 1);
            while (n < len && nums[n] == 0) ++n;

            if (n >= len || z >= len) break;
            swap(nums[z], nums[n]);
        }
    }
};