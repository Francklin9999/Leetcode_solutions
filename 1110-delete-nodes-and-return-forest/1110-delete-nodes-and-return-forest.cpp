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
    bool dfs(std::unordered_set<int>& del, TreeNode* root, std::vector<TreeNode*>& out) {
        if (root == nullptr) return false;

        auto left = dfs(del, root->left, out);
        auto right = dfs(del, root->right, out);

        if (left) root->left = nullptr;
        if (right) root->right = nullptr;

        auto is_root = del.contains(root->val);

        if (is_root && root->left) out.push_back(root->left);
        if (is_root && root->right) out.push_back(root->right);

        return is_root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::unordered_set<int> del(to_delete.begin(), to_delete.end());

        vector<TreeNode*> out;
        dfs(del, root, out);

        if (!del.contains(root->val)) out.push_back(root);

        return out;
    }
};