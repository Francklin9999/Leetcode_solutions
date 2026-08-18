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
int helper(TreeNode* root, bool& isBalance) {
    if (root == nullptr) return 0;

    auto left = helper(root->left, isBalance);
    auto right = helper(root->right, isBalance);

    if (std::abs(left - right) > 1) isBalance = false;

    return std::max(left, right) + 1;
}
public:
    bool isBalanced(TreeNode* root) {
        bool isBalance{true};
        helper(root, isBalance);
        return isBalance;
    }
};