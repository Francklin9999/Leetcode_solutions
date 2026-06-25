class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res{nums[0]};
        int curMin{1};
        int curMax{1};

        for (int num : nums) {
            if (num == 0) {
                res = std::max(0, res);
                curMin = 1;
                curMax = 1;
                continue;
            }
            int tmp = num * curMax;
            curMax = std::max({tmp, num * curMin, num});
            curMin = std::min({tmp, num * curMin, num});
            res = std::max(curMax, res);
        }

        return res;
    }
};