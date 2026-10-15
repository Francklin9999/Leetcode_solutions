class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto min = *std::min_element(nums.begin(), nums.end());
        auto max = *std::max_element(nums.begin(), nums.end());

        std::unordered_set<int> elements(nums.begin(), nums.end());

        std::vector<int> missing;

        for (int i{min + 1}; i < max; ++i) {
            if (!elements.contains(i)) missing.push_back(i);
        }

        return missing;
    }
};