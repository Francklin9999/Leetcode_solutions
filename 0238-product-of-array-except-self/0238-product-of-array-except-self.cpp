class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size(), 1);

        int running_prod{1};
        for (auto i{0uz}; i < sol.size(); ++i) {
            sol[i] *= running_prod;
            running_prod *= nums[i];
        }

        running_prod = 1;
        for (auto i{sol.size()}; i-- > 0; ) {
            sol[i] *= running_prod;
            running_prod *= nums[i];
        }

        return sol;
    }
};