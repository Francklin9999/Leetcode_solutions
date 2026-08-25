class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> miss;

        for (auto i{0uz}; i < nums.size(); ++i) {
            if (nums[i] % k == 0) miss.push_back(nums[i]);
        }

        sort(miss.begin(), miss.end());

        int j{0};
        for (auto i{0uz}; i < miss.size(); ++i) {
            if (i < miss.size() - 1 && miss[i] == miss[i + 1]) continue;
            j += k;
            if (miss[i] != j) return j;
        }

        return j + k;
    }
};