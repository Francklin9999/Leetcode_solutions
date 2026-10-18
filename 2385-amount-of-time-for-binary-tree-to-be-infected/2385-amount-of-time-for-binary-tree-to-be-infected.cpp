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
    void buildGraph(TreeNode* root, std::unordered_map<int, std::vector<int>>& graph) {
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left, graph);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        std::unordered_map<int, std::vector<int>> graph;

        buildGraph(root, graph);

        std::queue<int> q;
        std::unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int time{-1};

        while (!q.empty()) {
            auto sz = q.size();
            for (std::size_t i{0}; i < sz; ++i) {
                auto next = q.front();
                q.pop();

                for (const auto& val : graph[next]) {
                    if (visited.contains(val)) continue;

                    visited.insert(val);
                    q.push(val);
                }
            }

            ++time;
        }

        return time;
    }
};