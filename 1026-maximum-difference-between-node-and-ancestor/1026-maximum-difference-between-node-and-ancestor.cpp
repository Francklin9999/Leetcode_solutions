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
    std::pair<int, int> dfs(TreeNode* root, int& total) {
        auto left = root->left ? dfs(root->left, total) : make_pair(root->val, root->val);
        auto right = root->right ? dfs(root->right, total) : make_pair(root->val, root->val);

        total = std::max({total, std::abs(root->val - left.first), std::abs(root->val - left.second)});
        total = std::max({total, std::abs(root->val - right.first), std::abs(root->val - right.second)});

        return make_pair(std::min({left.first, right.first, root->val}), std::max({left.second, right.second, root->val}));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int total{};
        dfs(root, total);
        return total;
    }
};