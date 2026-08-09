class Solution {
struct Trie {
    char c;
    unordered_map<char, Trie*> trie;
    bool is_end_of_word{false};
    Trie(char _c) : c(_c) { }
};

unordered_map<char, Trie*> trie;

void insert(string word) {
    int i = 0;
    auto [it, _] = trie.try_emplace(word[i], new Trie(word[i]));
    auto curr = it->second;
    i++;
    while (i < word.size()) {
        auto [it, _] = curr->trie.try_emplace(word[i], new Trie(word[i]));
        curr = it->second;
        i++;
    }
    
    curr->is_end_of_word = true;
}


public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict) {
            insert(word);
        }

        vector<bool> dp(s.size() + 1);
        std::fill(dp.begin(), dp.end(), false);
        dp[0] = true;

        for (auto i = 0uz; i < s.size(); ++i) {
            if (!dp[i]) continue;

            auto curr = trie;
            int j = i;
            while (j < s.size() && curr.find(s[j]) != curr.end()) {
                if (curr[s[j]]->is_end_of_word) dp[j + 1] = true;
                curr = curr[s[j]]->trie;
                j++;
            }
        }

        return dp[dp.size() - 1]; 
    }
};