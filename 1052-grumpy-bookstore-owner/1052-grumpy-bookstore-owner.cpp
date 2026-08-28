class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int curr{};

        for (int i{0}; i < minutes; ++i) {
            if (grumpy[i] == 0) continue;
            curr += customers[i];
        }

        int res{curr};
        int i{0}, j{minutes - 1};

        for (std::size_t l{0}, r = minutes; r < customers.size(); ++l, ++r) {
            if (grumpy[r] == 1) curr += customers[r];
            if (grumpy[l] == 1) curr -= customers[l];

            if (curr > res) {
                res = curr;
                i = l + 1;
                j = r;
            }
        }

        res = 0;
        for (auto z{0uz}; z < customers.size(); ++z) {
            if (grumpy[z] == 0 || (z >= i && z <= j)) res += customers[z];
        }

        return res;
    }
};