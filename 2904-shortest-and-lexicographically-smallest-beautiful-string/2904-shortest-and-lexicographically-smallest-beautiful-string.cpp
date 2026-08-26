class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";

        int l{};
        int n{};

        for (auto i{0uz}; i < s.size(); ++i) {
            if (s[i] == '1') ++n;

            if (n == k) {
                while (s[l] != '1') ++l;

                string curr = s.substr(l, i - l + 1);

                if (res == "" ||
                    curr.size() < res.size() ||
                    (curr.size() == res.size() && curr < res)) {
                    res = curr;
                }
                
                while (n == k && l < i) {
                    if (s[l]  == '1') --n;
                    ++l;
                }

                while (l < i && s[l] != '1') ++l;
            }
        }

        return res;
    }
};