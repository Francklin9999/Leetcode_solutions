class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l{};
        int r{};

        while (l < version1.size() && r < version2.size()) {
            string curr1 = "";
            string curr2 = "";

            while (l < version1.size() && version1[l] == '0') ++l;
            while (l < version1.size() && version1[l] != '.') {
                curr1 += version1[l++];
            }

            while (r < version2.size() && version2[r] == '0') ++r;
            while (r < version2.size() && version2[r] != '.') {
                curr2 += version2[r++];
            }

            int n1{};
            if (curr1 != "")
                n1 = std::stoi(curr1);

            int n2{};
            if (curr2 != "")
                n2 = std::stoi(curr2);

            if (n1 > n2) return 1;
            if (n1 < n2) return -1;

            ++l;
            ++r;
        }

        while (l < version1.size()) {
            if (version1[l] != '0' && version1[l] != '.') return 1;
            ++l;
        }

        while (r < version2.size()) {
            if (version2[r] != '0' && version2[r] != '.') return -1;
            ++r;
        }

        return 0;
    }
};