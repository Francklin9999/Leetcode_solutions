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
    int dfs(TreeNode* root, int& moves) {
        if (root == nullptr) return 0;

        auto left = dfs(root->left, moves);
        auto right = dfs(root->right, moves);

        int curr = root->val + left + right - 1;

        moves += std::abs(curr);

        return curr;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves{};

        dfs(root, moves);
        return moves;
    }
};