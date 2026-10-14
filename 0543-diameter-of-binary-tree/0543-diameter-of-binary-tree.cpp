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
    int dfs(TreeNode* root, int& sum) {
        if (root == nullptr) return 0;

        auto left = dfs(root->left, sum);
        auto right = dfs(root->right, sum);

        sum = std::max(sum, left + right);

        return std::max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int sum{};
        dfs(root, sum);
        return sum;
    }
};