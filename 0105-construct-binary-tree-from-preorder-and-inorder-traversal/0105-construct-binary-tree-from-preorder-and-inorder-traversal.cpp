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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = std::find(inorder.begin(), inorder.end(), preorder[0]);
        int leftSize = static_cast<int>(it - inorder.begin());

        std::vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftSize + 1);
        std::vector<int> leftInorder(inorder.begin(), it);
        root->left = buildTree(leftPreorder, leftInorder);

        std::vector<int> rightPreorder(preorder.begin() + leftSize + 1, preorder.end());
        std::vector<int> rightInorder(it + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};