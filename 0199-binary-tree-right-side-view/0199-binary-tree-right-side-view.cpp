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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> view;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            auto size = q.size();
            for (auto i{0uz}; i < size; ++i) {
                auto front = q.front();
                q.pop();
                if (i == 0) view.push_back(front->val);
                if (front->right) q.push(front->right);
                if (front->left) q.push(front->left);
            }
        }

        return view;
    }
};