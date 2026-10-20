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
private:
    bool isPalindromic(std::vector<int>& freq) {
        auto count = std::count_if(freq.begin(), freq.end(), [](const auto& a) {
            return a % 2 != 0;
        });

        // if (freq.size() % 2 == 0) return count == 0;

        return count <= 1;
    }

    void dfs(TreeNode* root, std::vector<int>& freq, int& count) {
        if (!root) return;
        freq[root->val - 1]++;
        if (!root->left && !root->right) {
            count += isPalindromic(freq);
        } else {
            dfs(root->left, freq, count);
            dfs(root->right, freq, count);
        }
        freq[root->val - 1]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        std::vector<int> freq(9, 0);

        int count{};
        dfs(root, freq, count);

        return count;
    }
};