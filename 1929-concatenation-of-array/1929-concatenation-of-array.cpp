class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        res.resize(nums.size() * 2);

        auto len = nums.size();
        for (auto i{0uz}; i < len; ++i) {
            res[i] = nums[i];
            res[i + len] = nums[i];
        }

        return res;
    }
};