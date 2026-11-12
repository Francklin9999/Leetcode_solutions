class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> prefix;
        int len = 0;

        for (auto word : words) {
            if (word.size() < k) continue;
            auto sub = word.substr(0, k);
            prefix[sub]++;
        }

        for (auto& it : prefix) {
            if (it.second > 1) ++len;
        }

        return len;
    }
};