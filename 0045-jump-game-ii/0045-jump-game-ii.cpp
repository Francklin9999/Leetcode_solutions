class Solution {
public:
    int jump(vector<int>& nums) {
        int curr{};
        int farthest{};
        int j{};

        for (auto i{0uz}; i < nums.size() - 1; ++i) {
            farthest = std::max(farthest, static_cast<int>(i) + nums[i]);

            if (i == curr) {
                ++j;
                curr = farthest;
                farthest = 0;
                if (curr == nums.size() - 1) return j;
            }
        }

        return j;
    }
};