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
    int dfs(TreeNode* root, int& total) {
        if (root == nullptr) return 0;

        auto left = dfs(root->left, total);
        auto right = dfs(root->right, total);

        total += std::abs(left - right);

        return root->val + left + right;
    }
public:
    int findTilt(TreeNode* root) {
        int total{};
        dfs(root, total);
        return total;
    }
};