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
    int dfs(TreeNode* root, int& mx) {
        auto left = root->left ? dfs(root->left, mx) : 0;
        auto right = root->right ? dfs(root->right, mx) : 0;

        auto l = root->left && root->left->val == root->val;
        auto r = root->right && root->right->val == root->val; 

        left = l ? left + 1 : 0;
        right = r ? right + 1 : 0;

        mx = std::max(mx, left + right);
        
        return std::max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        int mx{};
        dfs(root, mx);
        return mx;
    }
};