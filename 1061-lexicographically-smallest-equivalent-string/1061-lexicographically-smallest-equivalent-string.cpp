class Solution {
private:
    std::vector<int> parent;
    std::vector<int> size;

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }

        return parent[a];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (size[b] > size[a]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        size.resize(26, 1);

        std::iota(parent.begin(), parent.end(), 0);

        for (std::size_t i{0}; i < s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        std::unordered_map<int, char> smallest;

        for (std::size_t i{0}; i < parent.size(); ++i) {
            auto idx = find(parent[i]);
            if (auto it = smallest.find(idx); it == smallest.end()) {
                smallest[idx] = 'a' + i;
            }
        }

        string s;

        for (std::size_t i{0}; i < baseStr.size(); ++i) {
            char c = smallest[find(baseStr[i] - 'a')];
            s.push_back(c);
        }

        return s;
    }
};