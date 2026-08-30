class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s) ++freq[c];

        int len{};

        for (auto& [_, value] : freq) len = std::max(len, value);
        
        vector<vector<char>> bucket(len + 1);

        for (auto& [key, value] : freq) bucket[value].push_back(key);

        string res{};

        for (auto i{bucket.size()}; i-- > 0; ) {
            sort(bucket[i].begin(), bucket[i].end());

            for (char c : bucket[i]) res.append(i, c);
        }

        return res;
    }
};