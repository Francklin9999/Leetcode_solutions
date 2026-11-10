class Solution {
int dfs(vector<int>& nums, vector<vector<int>>& cache, int l, int r) {
    if (l > r) return 0;
    if (cache[l][r] != INT_MAX) return cache[l][r];

    cache[l][r] = std::max(
        nums[l] - dfs(nums, cache, l + 1, r),
        nums[r] - dfs(nums, cache, l, r - 1)
    );

    return cache[l][r];
}
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> cache(nums.size(), vector<int>(nums.size(), INT_MAX));

        return dfs(nums, cache, 0, nums.size() - 1) >= 0;
    }
};