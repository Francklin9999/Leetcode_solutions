class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int occ = 1;

        for (auto i{1uz}; i < nums.size(); ++i) {
            if (nums[i] != num) --occ;
            else ++occ;

            if (occ == 0) {
                num = nums[i];
                occ = 1;
            }
        }

        return num;
    }
};