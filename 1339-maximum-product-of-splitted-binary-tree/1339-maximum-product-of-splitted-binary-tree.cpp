/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    constexpr static int mod = 1e9 + 7;

    int sum(TreeNode* root) {
        if (root == nullptr) return 0;

        return sum(root->left) + sum(root->right) + root->val;
    }

    int dfs(TreeNode* root, int s, long long& mx) {
        if (root == nullptr) return 0;

        auto left = dfs(root->left, s, mx);
        auto right = dfs(root->right, s, mx);

        auto curr = root->val + left + right;

        mx = std::max(mx, static_cast<long long>(curr) * (s - curr));

        return curr;
    }
public:
    int maxProduct(TreeNode* root) {
        int s = sum(root);

        long long mx{};
        dfs(root, s, mx);
        return mx % mod;
    }
};