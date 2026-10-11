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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        helper(order, root);
        return order;
    }

    void helper(vector<int>& order, TreeNode* root) {
        if (root == nullptr) return;

        order.push_back(root->val);
        helper(order, root->left);
        helper(order, root->right);
    }
};