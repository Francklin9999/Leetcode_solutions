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
void dfs(vector<int>& order, TreeNode* root) {
    if (root == nullptr) return;

    dfs(order, root->left);
    dfs(order, root->right);
    order.push_back(root->val);
}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        dfs(order, root);
        return order;
    }
};