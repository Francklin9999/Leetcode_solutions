class Solution {
vector<int> parent;
vector<int> rank;

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

    if (rank[b] < rank[a]) swap(b, a);

    parent[b] = a;
    rank[b] += rank[a];

    return true;
}

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size() + 1);
        rank.resize(edges.size() + 1);

        std::iota(parent.begin(), parent.end(), 0);
        std::fill(rank.begin(), rank.end(), 1);

        vector<int> redundant(2, 0);

        for (const auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                redundant[0] = edge[0];
                redundant[1] = edge[1];
            }
        }

        return redundant;
    }
};