class Solution {
void dfs(vector<int>& nums, vector<vector<int>>& perm, vector<int>& curr, size_t n) {
    if (n == nums.size()) {
        perm.push_back(curr);
        return;
    }

    auto sz = curr.size();
    for (auto i{0uz}; i <= sz; ++i) {
        curr.insert(curr.begin() + i, nums[n]);
        dfs(nums, perm, curr, n + 1);
        curr.erase(curr.begin() + i);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perm;
        vector<int> curr;

        dfs(nums, perm, curr, 0);
        return perm;
    }
};