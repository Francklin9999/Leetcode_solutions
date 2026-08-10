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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;

        int curr{};
        bool left = root->val >= low;
        bool right = root->val <= high;

        if (left) {
            curr += rangeSumBST(root->left, low, high);
        }

        if (right) {
            curr += rangeSumBST(root->right, low, high);
        }

        if (left && right) curr += root->val;

        return curr;
    }
};