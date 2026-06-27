class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (auto i = 1uz; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};