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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> order;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto size = q.size();
            vector<int> curr;
            curr.reserve(size);
            for (auto i{0uz}; i < size; ++i) {
                auto front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                curr.push_back(front->val);
            }

            order.push_back(curr);
        }

        return order;
    }
};