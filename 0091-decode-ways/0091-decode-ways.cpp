class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> map;
        return dfs(0, s, map);
    }

    int dfs(int i, string s, unordered_map<int, int>& map) {
        if (map[i]) return map[i];
        if (i > s.size()) return 0;
        if (i == s.size()) return 1;
        if (s.at(i) == '0') return 0;

        int first = dfs(i + 1, s, map);
        int sec = 0;
        if (std::stoi(s.substr(i, 2)) <= 26)
            sec = dfs(i + 2, s, map);
        map[i] = first + sec;
        return first + sec;
    }
};