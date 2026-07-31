class Solution {
int arr[27] {1, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 16, 18, 20, 22, 24, 27, 30, 33, 36, 39, 42, 45, 48, 52, 56};
public:
    int minimumPushes(string word) {
        int count[26]{};

        for (auto i = 0uz; i < word.size(); i++) {
            count[word.at(i) - 'a'] = 1;
        }

        int total{};
        for (auto i = 0; i < 26; i++) {
            total += count[i] & 1;
        }

        return arr[total];
    }
};