class Trie {
struct Node {
    char c;
    unordered_map<char, Node*> trie;
    bool end{false};
};

Node* head;
public:
    Trie() : head(new Node('\0')) {
        
    }
    
    void insert(string word) {
        auto curr = head;
        for (auto c : word) {
            auto it = curr->trie.find(c);
            if (it == curr->trie.end()) {
                curr->trie[c] = new Node(c);
            }
            curr = curr->trie[c];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        auto curr = head;
        for (auto c : word) {
            auto it = curr->trie.find(c);
            if (it == curr->trie.end()) return false; 
            curr = it->second;
        }

        return curr->end;
    }
    
    bool startsWith(string prefix) {
        auto curr = head;
        for (auto c : prefix) {
            auto it = curr->trie.find(c);
            if (it == curr->trie.end()) return false; 
            curr = it->second;
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