class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::size_t l{}, r{nums.size()}, i{};

        while(i < r) {
            if (nums[i] == 0) swap(nums[i++], nums[l++]);
            else if (nums[i] == 2) swap(nums[i], nums[--r]);
            else ++i;
        }
    }
};