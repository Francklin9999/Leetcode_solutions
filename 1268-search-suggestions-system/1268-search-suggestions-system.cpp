class Solution {
struct TrieNode {
    char c;
    map<char, TrieNode*> trie;
    bool end{false};
    TrieNode(char _c) : c(_c) {}
};

void insert(const string& s) {
    size_t i{0};
    auto curr = root;

    while (i < s.size()) {
        auto it = curr->trie.find(s[i]);
        if (it == curr->trie.end()) curr->trie[s[i]] = new TrieNode(s[i]);

        curr = curr->trie[s[i]];
        ++i;
    }

    curr->end = true;
}

void find(vector<string>& res, const string& s, size_t idx, string& str, TrieNode* head) {
    if (res.size() == 3) return;

    if (idx < s.size()) {
        auto it = head->trie.find(s[idx]);
        if (it == head->trie.end()) return;
        str.push_back(s[idx]);
        find(res, s, idx + 1, str, it->second);
        str.pop_back();
        return;
    }

    if (head->end) {
        res.push_back(str);
    }

    for (auto& [key, value] : head->trie) {
        str.push_back(key);
        find(res, s, idx, str, value);
        str.pop_back();
        if (res.size() == 3) return;
    }
}

TrieNode* root;

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode('\0');

        for (auto str : products) {
            insert(str);
        }

        vector<vector<string>> res;

        for (auto i{0uz}; i < searchWord.size(); ++i) {
            vector<string> str;
            string s{};
            find(str, searchWord.substr(0, i + 1), 0, s, root);
            res.push_back(str);
        }

        return res;
    }
};