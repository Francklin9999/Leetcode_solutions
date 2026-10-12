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
int diameter{};
int dfs(TreeNode* head) {
    if (head == nullptr) return 0;

    auto left = dfs(head->left);
    auto right = dfs(head->right);

    diameter = std::max(diameter, left + right);

    return std::max(left, right) + 1;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};