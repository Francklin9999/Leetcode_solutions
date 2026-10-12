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
void inorder(vector<TreeNode*>& order, TreeNode* root) {
    if (root == nullptr) return;

    inorder(order, root->left);
    order.push_back(root);
    inorder(order, root->right);
}

TreeNode* build(vector<TreeNode*>& order, int l, int r) {
    if (l > r) return nullptr;

    int mid = l + (r - l) / 2;

    order[mid]->left = build(order, l, mid - 1);
    order[mid]->right = build(order, mid + 1, r);

    return order[mid];
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<TreeNode*> order;
        inorder(order, root);

        for (auto i{0uz}; i < order.size(); ++i) {
            if (order[i]->val == key) {
                delete order[i];
                order.erase(order.begin() + i);
                break;
            }
        }

        return build(order, 0, order.size() - 1);
    }
};