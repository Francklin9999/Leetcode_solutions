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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        int depth{};

        q.emplace(root);
        while (!q.empty()) {
            auto size = q.size();
            for (auto i{0uz}; i < size; ++i) {
                auto front = q.front();
                q.pop();
                if (front->left) q.emplace(front->left);
                if (front->right) q.emplace(front->right);
            }

            ++depth;
        }

        return depth;
    }
};