class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t l{}, r{1};

        while (1) {
            while (l < nums.size() && nums[l] != 0) ++l;
            r = std::max(l, r);
            while (r < nums.size() && nums[r] == 0) ++r;
            if (r == nums.size()) break;
            std::swap(nums[l], nums[r]);
            ++l;
            ++r;
        }
    }
};