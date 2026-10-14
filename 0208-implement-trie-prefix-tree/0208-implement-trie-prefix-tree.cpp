class Trie {
struct Node {
    std::array<Node*, 26> letters{};
    bool is_end_of_word{false};
};

Node* trie;
public:
    Trie() {
        trie = new Node();
    }
    
    void insert(string word) {
        auto curr = trie;
        for (std::size_t i{0}; i < word.size(); ++i) {
            if (!curr->letters[word[i] - 'a']) {
                curr->letters[word[i] - 'a'] = new Node();
            }
            curr = curr->letters[word[i] - 'a'];
        }

        curr->is_end_of_word = true;
    }
    
    bool search(string word) {
        auto curr = trie;
        for (std::size_t i{0}; i < word.size(); ++i) {
            if (!curr->letters[word[i] - 'a']) return false;
            curr = curr->letters[word[i] - 'a'];
        }

        return curr->is_end_of_word;
    }
    
    bool startsWith(string prefix) {
        auto curr = trie;
        for (std::size_t i{0}; i < prefix.size(); ++i) {
            if (!curr->letters[prefix[i] - 'a']) return false;
            curr = curr->letters[prefix[i] - 'a'];
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