class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min{INT_MAX};
        int res{};
        int l, r;
        sort(nums.begin(), nums.end());

        for (auto i = 0uz; i < nums.size() - 2; i++) {
            l = i + 1;
            r = nums.size() - 1;

            while (l < r) {
                auto sum = (nums[i] + nums[l] + nums[r]);
                if (std::abs(sum - target) < min) {
                    min = std::abs(sum - target);
                    res = sum;
                }

                if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return res;
    }
};