class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> leftToRight(nums.size());
        leftToRight[0] = 0;
        vector<int> rightToLeft(nums.size());
        rightToLeft[nums.size() - 1] = 0;

        for (int i = 1; i < nums.size(); i++) {
            leftToRight[i] = nums[i - 1] + leftToRight[i - 1];
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            rightToLeft[i] = nums[i + 1] + rightToLeft[i + 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (leftToRight[i] == rightToLeft[i]) return i;
        } 

        return -1;
    }
};