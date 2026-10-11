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
    int findBottomLeftValue(TreeNode* root) {
        if (root  == nullptr) return -1;
        queue<TreeNode*> q;
        int res{root->val};

        q.emplace(root);
        while (!q.empty()) {
            auto& t = q.front();
            if (t) res = t->val;
            if (t->right) q.emplace(t->right);
            if (t->left) q.emplace(t->left);
            q.pop();
        }

        return res;
    }
};