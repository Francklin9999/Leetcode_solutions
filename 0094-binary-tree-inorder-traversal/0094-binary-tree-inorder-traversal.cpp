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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        std::vector<int> order;
        std::stack<pair<TreeNode*, bool>> stack;
        stack.emplace(root, false);

        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            
            if (!top.second) {
                top.second = true;
                if (top.first->right)
                    stack.emplace(top.first->right, false);
                stack.emplace(top);
                if (top.first->left)
                    stack.emplace(top.first->left, false);
            } else {
                order.push_back(top.first->val);
            }
        }

        return order;
    }
};