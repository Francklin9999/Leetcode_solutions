class TrieNode {
public:
    unordered_map<char, TrieNode*> trie;
    bool endOfWord{false};
};


class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto curr = root;
        for (char c : word) {
            if (curr->trie.find(c) != curr->trie.end()) {
                curr = curr->trie.at(c);
            } else {
                curr->trie[c] = new TrieNode();
                curr = curr->trie.at(c);
            }
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, root);
    }

    bool dfs(string word, TrieNode* root) {
        auto curr = root;
        for (auto i = 0uz; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto& entry : curr->trie) {
                    if(dfs(word.substr(i + 1), entry.second)) return true;
                }
                return false;
            }
            if (curr->trie.find(word[i]) != curr->trie.end()) {
                curr = curr->trie.at(word[i]);
            } else return false;
        }

        return curr->endOfWord;
    }

private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */