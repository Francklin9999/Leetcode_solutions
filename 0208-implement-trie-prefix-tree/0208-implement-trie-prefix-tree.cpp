class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool end_of_word{false};
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto curr = root;
        for (char c : word) {
            if (curr->child.find(c) != curr->child.end()) {
                curr = (curr->child).at(c);
            } else {
                curr->child[c] = new TrieNode();
                curr = (curr->child).at(c);
            }
        }
        curr->end_of_word = true;
    }
    
    bool search(string word) {
        auto curr = root;
        for (char c : word) {
            if (curr->child.find(c) != curr->child.end()) {
                curr = curr->child[c];
            } else return false;
        }

        return curr->end_of_word;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        for (char c : prefix) {
            if (curr->child.find(c) != curr->child.end()) {
                curr = curr->child[c];
            } else return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */