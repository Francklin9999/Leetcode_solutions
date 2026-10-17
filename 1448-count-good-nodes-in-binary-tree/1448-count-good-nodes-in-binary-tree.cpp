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
    void dfs(TreeNode* root, int& total, int mx) {
        if (root == nullptr) return;

        if (root->val >= mx) ++total;

        mx = std::max(mx, root->val);
        dfs(root->left, total, mx);
        dfs(root->right, total, mx);
    }
public:
    int goodNodes(TreeNode* root) {
        int total{};
        dfs(root, total, std::numeric_limits<int>::min());
        return total;
    }
};