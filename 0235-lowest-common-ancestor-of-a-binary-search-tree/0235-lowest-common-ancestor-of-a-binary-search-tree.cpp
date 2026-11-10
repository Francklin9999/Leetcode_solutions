/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;

        auto left = (p->val < root->val || q->val < root->val) ? lowestCommonAncestor(root->left, p, q) : nullptr;
        auto right = (p->val > root->val || q->val > root->val) ? lowestCommonAncestor(root->right, p, q) : nullptr;

        if (left && right) return root;

        return left ? left : right;
    }
};