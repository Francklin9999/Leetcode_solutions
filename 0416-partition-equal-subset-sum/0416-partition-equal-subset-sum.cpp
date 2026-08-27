class Solution {
bool helper(vector<int>& nums, vector<vector<int>>& curr, int idx, int sum, int total) {
    if (sum == total) return true;
    if (sum > total) return false;
    if (idx == nums.size()) return false;

    if (curr[idx][sum] != - 1) return curr[idx][sum];

    if (helper(
        nums,
        curr,
        idx + 1,
        sum + nums[idx],
        total
    )) {
        return curr[idx][sum] = true;
    }

    return curr[idx][sum] = helper(
        nums,
        curr,
        idx + 1,
        sum,
        total
    );
}
public:
    bool canPartition(vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        vector<vector<int>> curr(nums.size(), vector<int>(sum + 1, -1));
        return helper(nums, curr, 0, 0,  sum / 2);
    }
};