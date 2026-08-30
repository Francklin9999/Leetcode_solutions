class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l{}, res{};
        vector<int> freq(fruits.size() + 1, 0);
        int m{2};

        for (int r{}; r < fruits.size(); ++r) {
            if (freq[fruits[r]] == 0) --m;
            freq[fruits[r]]++;

            while (m < 0) {
                --freq[fruits[l]];
                if (freq[fruits[l++]] == 0) ++m;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};