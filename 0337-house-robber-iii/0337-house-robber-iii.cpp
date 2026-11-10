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
std::pair<int, int> dfs(TreeNode* root) {
    if (root == nullptr) return make_pair(0, 0);

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int take = root->val + left.second + right.second;
    int leave = left.first + right.first;

    return make_pair(std::max(take, leave), leave);
}
public:
    int rob(TreeNode* root) {
        auto curr = dfs(root);
        return std::max(curr.first, curr.second);
    }
};