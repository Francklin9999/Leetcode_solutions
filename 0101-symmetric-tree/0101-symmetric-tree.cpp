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
bool helper(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;

    auto child1 = helper(left->right, right->left);
    auto child2 = helper(left->left, right->right);

    if (child1 && child2 && (left->val == right->val)) return true;
    return false;
}
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};