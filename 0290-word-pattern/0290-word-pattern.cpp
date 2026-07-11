class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        constexpr static char space = ' ';
        size_t curr{};

        for (auto i = 0uz; i < pattern.size(); ++i) {
            string currWord{};
            
            while (curr < s.size() && s.at(curr) != space) {
                currWord += s.at(curr);
                curr++;
            }
            curr++;

            auto wordIt = charToWord.find(pattern.at(i));
            auto charIt = wordToChar.find(currWord);

            bool isWord = wordIt != charToWord.end();
            bool isChar = charIt != wordToChar.end();

            if ((isWord && !isChar) || (isChar && !isWord)) return false;

            if (!isWord && !isChar) {
                charToWord[pattern.at(i)] = currWord;
                wordToChar[currWord] = pattern.at(i);
            } else if (wordIt->first != charIt->second || charIt->first != wordIt->second) {
                return false;
            }
        }

        return curr == s.size() + 1;
    }
};