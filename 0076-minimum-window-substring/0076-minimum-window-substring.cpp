class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        int num{};

        for (char c : t) {
            auto it = count.find(c);
            if (it != count.end()) {
                it->second--;
            } else {
                count[c] = -1;
                num++;
            }
        }

        int l{};
        int r{};
        int curr{};
        int it1{-1};
        int it2{-1};
        int currSize{INT_MAX};

        while (r < s.size()) {
            auto it = count.find(s.at(r));
            if (it != count.end()) {
                it->second++;
                if (it->second == 0) {
                    curr++;
                }
            }

            while (curr >= num) {
                auto jt = count.find(s.at(l));
                if (jt != count.end()) {
                    jt->second--;
                    if (jt->second < 0)
                        curr--;
                }
                if ((r - l) < currSize) {
                    currSize = r - l + 1;
                    it1 = l;
                    it2 = r;
                }
                l++;
            }
            r++;
        }

        if (it1 != -1)
            return s.substr(it1, it2 - it1 + 1);
        
        return "";
    }
};