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
    int rob(TreeNode* root) {
        auto help = helper(root, 0, 0);
        return std::max(help.first, help.second);
    }

    pair<int, int> helper(TreeNode* root, int took, int leave) {
        if (root == nullptr) return pair<int, int>(0, 0);

        auto [f1, f2] = helper(root->left, 0, 0);
        auto [l1, l2] = helper(root->right, 0, 0);

        return pair<int, int>(
            root->val + f2 + l2,
            std::max(f1, f2) + std::max(l1, l2)
        );
    }
};