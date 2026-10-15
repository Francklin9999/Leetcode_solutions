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
    constexpr static int mod = 1e9 + 7;

    int sum(TreeNode* root) {
        if (root == nullptr) return 0;

        return root->val + sum(root->left) + sum(root->right);
    }

    int dfs(TreeNode* root, long long s, long long& product) {
        if (root == nullptr) return 0;

        auto left = dfs(root->left, s, product);
        auto right = dfs(root->right, s, product);

        long long total = left + right + root->val;

        product = std::max(product, total * (s - total));

        return total;
    }
public:
    int maxProduct(TreeNode* root) {
        long long product{};
        auto s = sum(root);

        dfs(root, s, product);

        return product % mod;
    }
};