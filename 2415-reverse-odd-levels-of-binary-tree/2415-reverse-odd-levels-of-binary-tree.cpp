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
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        bool process{false};

        while (!q.empty()) {
            auto sz = q.size();
            if (process) {
                for (std::size_t i{0}; i < sz; ++i) {
                    auto front = q.front();
                    q.pop();

                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
            } else {
                std::vector<TreeNode*> node;
                std::vector<int> val;
                for (std::size_t i{0}; i < sz; ++i) {
                    auto front = q.front();
                    q.pop();

                    if (front->left) {
                        q.push(front->left);
                        node.push_back(front->left);
                        val.push_back(front->left->val);
                    }
                    if (front->right) {
                        q.push(front->right);
                        node.push_back(front->right);
                        val.push_back(front->right->val);
                    }
                }

                reverse(val.begin(), val.end());

                for (std::size_t i{0}; i < val.size(); ++i) {
                    node[i]->val = val[i];
                }
            }

            process = !process;
        }

        return root;
    }
};