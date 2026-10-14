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
    pair<int, int> dfs(TreeNode* root, int& diff) {
        auto left = root->left ? dfs(root->left, diff) : make_pair(root->val, root->val);
        auto right = root->right ? dfs(root->right, diff) : make_pair(root->val, root->val);

        auto min = std::min(left.first, right.first);
        auto max = std::max(left.second, right.second);

        diff = std::max({diff, std::abs(root->val - min), std::abs(root->val - max)});

        return {std::min(min, root->val), std::max(max, root->val)};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;
        int diff{};
        dfs(root, diff);
        return diff;
    }
};