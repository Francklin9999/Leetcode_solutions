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
    string tree2str(TreeNode* root) {
        auto left = root->left ? tree2str(root->left) : "";
        auto right = root->right ? tree2str(root->right) : "";

        std::string curr = std::to_string(root->val);

        if (left != "") curr += '(' + left + ')';
        
        if (right != "" && left == "") curr += "()(" + right + ')';
        else if (right != "") curr += '(' + right + ')';

        return curr;
    }
};