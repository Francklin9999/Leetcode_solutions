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
    std::pair<int, int> dfs(TreeNode* root, int& path) {
        if (root == nullptr) return make_pair(-1, -1);

        auto left = dfs(root->left, path);
        auto right = dfs(root->right, path);

        int mx = std::max(left.first, right.second) + 1;

        path = std::max(path, mx);

        return make_pair(right.second + 1, left.first + 1);
    }
public:
    int longestZigZag(TreeNode* root) {
        int path{};
        dfs(root, path);
        return path;
    }
};