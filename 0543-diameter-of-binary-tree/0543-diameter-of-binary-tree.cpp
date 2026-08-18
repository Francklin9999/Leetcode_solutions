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
int helper(TreeNode* root, int& res) {
    if (root == nullptr) return 0;

    auto left = helper(root->left, res);
    auto right = helper(root->right, res);

    res = std::max(res, left + right);
    return std::max(left, right) + 1;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res{};
        helper(root, res);
        return res;
    }
};