/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void helper(vector<int>& res, Node* root) {
        if (root == nullptr) return;
        for (auto i{0uz}; i < root->children.size(); ++i) {
            helper(res, root->children[i]);
        }
        res.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(res, root);
        return res;
    }
};