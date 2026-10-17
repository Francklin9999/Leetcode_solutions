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
std::pair<int, TreeNode*> helper(TreeNode* root) {
    if (root == nullptr) return make_pair(0, root);

    auto left = helper(root->left);
    auto right = helper(root->right);

    if (left.first == right.first) return make_pair(left.first + 1, root);

    if (left.first > right.first) return make_pair(left.first + 1, left.second);

    return make_pair(right.first + 1, right.second);
}
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).second;
    }
};