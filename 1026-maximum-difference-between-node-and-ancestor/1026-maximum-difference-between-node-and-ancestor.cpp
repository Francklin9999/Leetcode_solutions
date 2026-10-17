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

        int mn = std::min(left.first, right.first);
        int mx = std::max(left.second, right.second);

        total = std::max(total, std::abs(root->val - mn));
        total = std::max(total, std::abs(root->val - mx));

        return make_pair(std::min(mn, root->val), std::max(mx, root->val));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int total{};
        dfs(root, total);
        return total;
    }
};