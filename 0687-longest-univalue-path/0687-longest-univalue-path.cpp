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
    int dfs(TreeNode* root, int& sum) {
        if (root == nullptr) return 0;

        auto left = dfs(root->left, sum);
        auto right = dfs(root->right, sum);

        bool l = root->left && root->val == root->left->val;
        bool r = root->right && root->val == root->right->val;

        int curr{1};

        if (l) curr = std::max(curr, left + 1);
        if (r) curr = std::max(curr, right + 1);

        int through = 1 + (l ? left : 0) + (r ? right : 0);

        sum = std::max(sum, through);

        return curr;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum{std::numeric_limits<int>::min()};
        dfs(root, sum);
        return sum - 1;
    }
};