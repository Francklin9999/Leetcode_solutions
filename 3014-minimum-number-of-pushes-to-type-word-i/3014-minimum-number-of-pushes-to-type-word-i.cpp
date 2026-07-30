class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char> set;
        int total{};

        for (auto i = 0uz; i < word.size(); i++) {
            set.insert(word[i]);
        }

        int k = set.size();
        int loop = 1;
        
        while (k > 0) {
            int take = min(k, 8);
            total += take * loop;
            k -= take;
            ++loop;
        } 

        return total;
    }
};