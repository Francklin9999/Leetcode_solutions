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
    bool dfs(TreeNode* root, int target, std::string& res) {
        if (root == nullptr) return false;
        if (root->val == target) return true;

        res.push_back('L');
        auto left = dfs(root->left, target, res);
        if (left) return left;
        res.pop_back();

        res.push_back('R');
        auto right = dfs(root->right, target, res);
        if (right) return right;
        res.pop_back();

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string start;
        dfs(root, startValue, start);

        std::string end;
        dfs(root, destValue, end);

        auto mn = std::min(start.size(), end.size());

        std::size_t i{0};
        for (; i < mn; ++i) {
            if (start[i] != end[i]) break;
        }

        std::string out;
        for (std::size_t j{i}; j < start.size(); ++j) {
            out.push_back('U');
        }

        for (std::size_t j{i}; j < end.size(); ++j) {
            out.push_back(end[j]);
        }

        return out;
    }
};