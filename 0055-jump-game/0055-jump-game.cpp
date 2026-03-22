class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currJump = 0;

        for (int i = 0; i < nums.size(); i++) {
            currJump = std::max(currJump, nums[i]);
            
            if (currJump + i >= nums.size() - 1) return true;
            if (currJump <= 0) return false;

            currJump--;
        }

        return false;
    }
};