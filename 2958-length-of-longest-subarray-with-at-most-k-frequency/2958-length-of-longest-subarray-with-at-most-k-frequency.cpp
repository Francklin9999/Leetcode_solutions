class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int total{};
        int res{};
        int l{};

        unordered_map<int, int> freq;

        for (auto i = 0uz; i < nums.size(); ++i) {
            auto it = freq.find(nums[i]);
            total++;

            if (it != freq.end()) {
                it->second++;
            }
            else {
                freq[nums[i]] = 1;
            }
            
            if (freq[nums[i]] > k) {
                while (freq[nums[i]] > k) {
                    --freq[nums[l++]];
                    total--;
                }
            }
            res = std::max(res, total);
        }

        return std::max(res, total);
    }
};