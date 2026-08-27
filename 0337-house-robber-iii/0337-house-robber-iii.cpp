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
pair<int, int> helper(TreeNode* root) {
    if (root == nullptr) return {0, 0};

    auto left = helper(root->left);
    auto right = helper(root->right);

    auto take = root->val + left.second + right.second;
    auto leave = std::max(left.first, left.second) + std::max(right.first, right.second);

    return {take, leave};
}
public:
    int rob(TreeNode* root) {
        auto run = helper(root);

        return std::max(run.first, run.second);
    }
};