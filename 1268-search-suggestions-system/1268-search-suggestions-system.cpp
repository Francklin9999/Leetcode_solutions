class Solution {
struct TrieNode {
    char c;
    map<char, TrieNode*> trie;
    bool end{false};
    TrieNode(char _c) : c(_c) { }
};

void insert(const string& s) {
    auto curr = root;
    size_t i{0};
    while (i < s.size()) {
        auto it = curr->trie.find(s[i]);
        if (it == curr->trie.end()) curr->trie[s[i]] = new TrieNode(s[i]);
        curr = curr->trie[s[i]];
        ++i;
    }

    curr->end = true;
}

void search(const string& s, string& curr, TrieNode* node, vector<string>& res, int idx) {
    if (idx == 0 && node->trie.find(s[0]) == node->trie.end()) return;
    if (res.size() == 3) return;

    if (idx >= 0 && idx < s.size()) {
        auto it = node->trie.find(s[idx]);
        if (it != node->trie.end()) {
            curr.push_back(s[idx]);
            search(s, curr, it->second, res, idx + 1);
            curr.pop_back();
            if (res.size() == 3) return;
            return;
        } else {
            return;
        }
    }

    if (node->end) res.push_back(curr);
    if (res.size() == 3) return;

    for (auto& [key, value] : node->trie) {
        curr.push_back(key);
        search(s, curr, value, res, -1);
        curr.pop_back();
        if (res.size() == 3) return;
    }
}

TrieNode* root;

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        root = new TrieNode('\0');

        for (auto& s : products) {
            insert(s);
        }

        for (auto i{0uz}; i < searchWord.size(); ++i) {
            string curr{""};
            vector<string> strs;
            search(searchWord.substr(0, i + 1), curr, root, strs, 0);
            res.push_back(strs);
        }

        return res;
    }
};