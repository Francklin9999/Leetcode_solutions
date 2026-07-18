struct NodeTrie {
    unordered_map<char, NodeTrie*> trie;
    bool is_end_of_word{false};
};

class Solution {
    NodeTrie* head;
    vector<string> res;
    vector<vector<int>> nei = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::size_t m;
    std::size_t n;

    void addWordToTrie(string& word) {
        auto curr = head;
        for (char c : word) {
            if (curr->trie.find(c) == curr->trie.end()) {
                curr->trie[c] = new NodeTrie();
            }
            curr = curr->trie[c];
        }

        curr->is_end_of_word = true;
    }

    void findWord(vector<vector<char>>& board, std::size_t i, std::size_t j, string& word, NodeTrie* node) {
        if (node->is_end_of_word) {
            res.push_back(word);
            node->is_end_of_word = false;
        }
        
        auto c = board[i][j];
        board[i][j] = '#';

        for (auto k = 0uz; k < nei.size(); ++k) {
            int x = static_cast<int>(i) + nei[k][0];
            int y = static_cast<int>(j) + nei[k][1];

            if (x >= m || y >= n || x < 0 || y < 0) continue;

            if (node->trie.find(board[x][y]) != node->trie.end()) {
                word.push_back(board[x][y]);
                findWord(board, x, y, word, node->trie[board[x][y]]);
                word.pop_back();
            }
        }

        board[i][j] = c;
    }

public:

    Solution() {
        head = new NodeTrie();
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        for (string& word : words) {
            addWordToTrie(word);
        }

        for (auto i = 0uz; i < m; ++i) {
            for (auto j = 0uz; j < n; ++j) {
                if (head->trie.find(board[i][j]) != head->trie.end()) {
                    string word{};
                    word.push_back(board[i][j]);
                    findWord(board, i, j, word, head->trie[board[i][j]]);
                    word.pop_back();
                }
            }
        }

        return res;
    }
};