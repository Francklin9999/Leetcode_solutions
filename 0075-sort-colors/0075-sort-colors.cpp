class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::size_t l{}, r{nums.size()}, idx{};

        while (idx < r) {
            if (nums[idx] == 0) std::swap(nums[idx++], nums[l++]);
            else if (nums[idx] == 2) std::swap(nums[idx], nums[--r]);
            else idx++;
        }
    }
};