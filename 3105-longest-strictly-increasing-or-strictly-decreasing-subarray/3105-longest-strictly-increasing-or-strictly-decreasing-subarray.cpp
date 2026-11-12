class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l{1};
        int up{1}, dec{1};

        for (auto i{1uz}; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++up;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                ++dec;
                up = 1;
            } else {
                up = 1;
                dec = 1;
            }

            l = std::max({l, up, dec});
        }

        return l;
    }
};