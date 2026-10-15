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
    int dfs(TreeNode* root, int& res) {
        if (root == nullptr) return 0;

        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);

        auto total = root->val + left + right;

        res += std::abs(total - 1);

        return total - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int res{};
        dfs(root, res);
        return res;
    }
};