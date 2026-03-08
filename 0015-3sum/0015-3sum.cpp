class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l, r;
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                int curr = nums[l] + nums[r] + nums[i];
                if (curr == 0) {
                    results.push_back({nums[l], nums[r], nums[i]});
                    r--;
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                } else if (curr > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return results;
    }
};