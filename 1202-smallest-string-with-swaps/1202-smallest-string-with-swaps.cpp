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
        size[a] += b;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent.resize(s.size());
        size.resize(s.size(), 0);

        std::iota(parent.begin(), parent.end(), 0);

        for (const auto& vec : pairs) {
            unite(vec[0], vec[1]);
        }

        std::unordered_map<int, std::pair<std::vector<int>, std::vector<char>>> mapping;

        for (std::size_t i{0}; i < parent.size(); ++i) {
            auto& bucket = mapping[find(parent[i])];
            bucket.first.push_back(i);
            bucket.second.push_back(s[i]);
        }

        std::string smallest;
        smallest.resize(s.size());

        for (auto& [_, value] : mapping) {
            auto& pos = value.first;
            auto& ch = value.second;

            sort(pos.begin(), pos.end());
            sort(ch.begin(), ch.end());

            for (std::size_t idx{0}; idx < pos.size(); ++idx) {
                smallest[pos[idx]] = ch[idx];
            }
        }

        return smallest;
    }
};