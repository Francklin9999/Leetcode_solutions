class Solution {
private:
    vector<int> parent;
    vector<int> size;

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }

        return parent[a];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (size[a] < size[b]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size() + 1);
        size.resize(edges.size() + 1);

        std::iota(parent.begin(), parent.end(), 0);
        std::fill(size.begin(), size.end(), 1);

        vector<int> res(2, 0);

        for (const auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                res[0] = edge[0];
                res[1] = edge[1];
            }
        }

        return res;
    }
};