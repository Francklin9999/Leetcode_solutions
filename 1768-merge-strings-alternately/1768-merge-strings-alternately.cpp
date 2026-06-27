class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string out;
        out.resize(word1.size() + word2.size());

        std::size_t w1{0};
        std::size_t w2{0};

        for (std::size_t i{0}; i < out.size();) {
            auto j = i;
            if (w1 < word1.size()) {
                out.at(j) = word1.at(w1);
                w1++;
                j++;
                i++;
            }
            if (w2 < word2.size()) {
                out.at(j) = word2.at(w2);
                w2++;
                i++;
            }
        }

        return out;
    }
};