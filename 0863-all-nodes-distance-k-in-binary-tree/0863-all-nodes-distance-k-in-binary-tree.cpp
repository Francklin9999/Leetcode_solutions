/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void buildGraph(std::unordered_map<int, std::vector<int>>& graph, TreeNode* root) {
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(graph, root->left);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(graph, root->right);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::unordered_map<int, std::vector<int>> graph;

        buildGraph(graph, root);

        std::unordered_set<int> visited;
        std::queue<int> q;
        q.push(target->val);
        visited.insert(target->val);
        int distance{0};

        while (!q.empty() && distance != k) {
            auto size = q.size();

            for (std::size_t i{0}; i < size; ++i) {
                auto node = q.front();
                q.pop();

                for (const auto& edge : graph[node]) {
                    if (visited.contains(edge)) continue;
                    q.push(edge);
                    visited.insert(edge);
                }
            }

            ++distance;
        }

        std::vector<int> res;

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};