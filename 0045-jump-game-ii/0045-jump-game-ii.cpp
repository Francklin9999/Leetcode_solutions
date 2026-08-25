class Solution {
public:
    int jump(vector<int>& nums) {
        int curr{};
        int farthest{};
        int j{};
        int sz = nums.size() - 1;

        for (auto i{0uz}; i < sz; ++i) {
            farthest = std::max(farthest, static_cast<int>(i) + nums[i]);

            if (i == curr) {
                ++j;
                curr = farthest;
            }
        }

        return j;
    }
};