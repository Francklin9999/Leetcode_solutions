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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        bool leaf = false;
        if (targetSum - root->val == 0 && !root->left && !root->right) {leaf = true; return true;}

        return (helper(root->left, targetSum - root->val, leaf) || helper(root->right, targetSum - root->val, leaf)) && leaf;
    }

    bool helper(TreeNode* root, int targetSum, bool& leaf) {
        if (!root) return false;
        if (targetSum - root->val == 0 && !root->left && !root->right) {leaf = true; return true;}

        return helper(root->left, targetSum - root->val, leaf) || helper(root->right, targetSum - root->val, leaf);
    }
};