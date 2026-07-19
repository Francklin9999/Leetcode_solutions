struct Node {
    Node(int p) : parent(p) {}
    int parent;
    int rank{};
};

class Solution {
    unordered_map<int, Node*> map;

    void buildUnion(int n) {
        for (int i{1}; i <= n; ++i) {
            map[i] = new Node(i);
        }
    }

    int find(int x) {
        auto parent = map[x]->parent;
        while (parent != map[parent]->parent) {
            parent = map[parent]->parent;
        }

        return parent;
    }

    bool connect(int x, int y) {
        Node* first = map[find(x)];
        Node* second = map[find(y)];

        if (first == second) return false;

        second->parent = first->parent;
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        buildUnion(static_cast<int>(edges.size()));
        int x;
        int y;

        for (auto& e : edges) {
            if (!connect(e[0], e[1])) {
                x = e[0];
                y = e[1];
            }
        }

        return {x, y};
    }
};