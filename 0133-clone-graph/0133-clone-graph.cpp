/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> cloneMap;
        queue<Node*> queue;
        queue.push(node);
        cloneMap[node] = new Node(node->val);

        while (!queue.empty()) {
            auto curr = queue.front();
            auto newNode = cloneMap[curr];
            for (auto nei : curr->neighbors) {
                auto it = cloneMap.find(nei);
                if (it == cloneMap.end()) {
                    cloneMap[nei] = new Node(nei->val);
                    queue.push(nei);
                }
                newNode->neighbors.push_back(cloneMap[nei]);
            }
            queue.pop();
        }

        return cloneMap[node];
    }
};