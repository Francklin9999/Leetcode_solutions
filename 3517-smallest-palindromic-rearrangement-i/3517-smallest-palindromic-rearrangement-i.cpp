class Solution {
public:
    string smallestPalindrome(string s) {
        int count[26]{};

        for (auto i = 0uz; i < s.size(); i++) {
            ++count[s.at(i) - 'a'];
        }

        string word{};
        string rev{};
        char next{};

        for (auto i = 0uz; i < 26; i++) {
            while (count[i] > 0) {
                if (count[i] == 1) {
                    next = static_cast<char>('a' + i);
                    --count[i];
                    continue; 
                }
                word += static_cast<char>('a' + i);
                --count[i];
                if (count[i] > 0) {
                    rev += static_cast<char>('a' + i);
                    --count[i];
                }
            }
        }        

        reverse(rev.begin(), rev.end());
        if (next != '\0') {
            return word + next + rev;
        }

        return word + rev;
    }
};