class Solution {
int helper(vector<int>& nums, vector<int>& curr, size_t idx) {
    if (idx == nums.size()) {
        int sum{};
        for (auto i{0uz}; i < curr.size(); ++i) {
            sum ^= curr[i];
        }

        return sum;
    }

    int n{};

    curr.push_back(nums[idx]);
    n += helper(nums, curr, idx + 1);
    curr.pop_back();
    n += helper(nums, curr, idx + 1);

    return n;
}
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> curr;
        return helper(nums, curr, 0);
    }
};