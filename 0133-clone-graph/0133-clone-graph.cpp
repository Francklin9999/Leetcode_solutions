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
private:
    std::unordered_map<Node*, Node*> clone;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (clone.find(node) != clone.end()) return clone[node];

        clone[node] = new Node(node->val);

        for (auto nei : node->neighbors) {
            clone[node]->neighbors.push_back(cloneGraph(nei));
        }    

        return clone[node];
    }
};