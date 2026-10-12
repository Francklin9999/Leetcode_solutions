class Solution {
void dfs(vector<int>& nums, vector<vector<int>>& subs, vector<int>& curr, size_t n) {
    if (n == nums.size()) {
        subs.push_back(curr);
        return;
    }

    curr.push_back(nums[n]);
    dfs(nums, subs, curr, n + 1);
    curr.pop_back();
    dfs(nums, subs, curr, n + 1);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> curr;
        dfs(nums, subs, curr, 0);
        return subs;
    }
};