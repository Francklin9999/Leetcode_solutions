class Solution {
public:
    int numDecodings(string s) {
        int next1 = 1;
        int next2 = 0;
        int curr = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s.at(i) == '0') {
            } else {
                curr += next1;
                int num = std::stoi(s.substr(i, 2));
                if (num <= 26 && num >= 10) curr += next2;
            }
            next2 = next1;
            next1 = curr;
            curr = 0;
        }

        return next1;
    }
};