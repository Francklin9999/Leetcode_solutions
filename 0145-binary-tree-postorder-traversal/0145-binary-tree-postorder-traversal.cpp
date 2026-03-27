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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return { };
        vector<int> answer;
        helper(root, answer);
        return answer;
    }

    void helper(TreeNode* root, vector<int>& answer) {
        if (root == nullptr) return;
        if (root->left) helper(root->left, answer);
        if (root->right) helper(root->right, answer);

        answer.push_back(root->val);
    }
};