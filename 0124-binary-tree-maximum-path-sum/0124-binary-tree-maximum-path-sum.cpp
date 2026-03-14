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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res) {
        if (root == nullptr) return 0;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        int curr = root->val;
        if (left > 0) curr += left;
        if (right > 0) curr += right;

        res = std::max(res, curr);

        return std::max(0, std::max(left, right)) + root->val;

    }
};