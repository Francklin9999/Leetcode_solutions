class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res(nums.size(), false);
        int curr{};

        for (auto i{0uz}; i < nums.size(); ++i) {
            curr = curr << 1;
            curr |= nums[i];
            res[i] = (curr % 5) == 0;
            curr = curr % 5;
        }

        return res;
    }
};