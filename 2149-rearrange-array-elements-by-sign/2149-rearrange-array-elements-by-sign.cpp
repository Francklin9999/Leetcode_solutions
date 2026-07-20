class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());

        size_t pos{0};
        size_t neg{1};

        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res[pos] = nums[i];
                pos += 2;
            } else {
                res[neg] = nums[i];
                neg += 2;
            }
        }

        return res;
    }
};