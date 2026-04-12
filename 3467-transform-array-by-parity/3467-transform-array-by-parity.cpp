class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)  {
            if (nums[i] % 2 == 0) {
                res.push_back(0);
            }
        }

        for (int i = 0; i < nums.size(); i++)  {
            if (nums[i] % 2 != 0) {
                res.push_back(1);
            }
        }

        return res;
    }
};