class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> before(nums.size(), 1);
        vector<int> after(nums.size(), 1);
        vector<int> res(nums.size());

        for (auto i = 1uz; i < nums.size(); ++i) {
            before[i] = nums[i - 1] * before[i - 1];
        }

        for (auto i = nums.size() - 1; i-- > 0;) {
            after[i] = nums[i + 1] * after[i + 1];
        }

        for (auto i = 0uz; i < res.size(); ++i) {
            res[i] = before[i] * after[i];
        }

        return res;
    }
};