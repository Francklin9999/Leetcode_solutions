class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res{};
        long long product{1};
        size_t l{0};

        for (auto r{0uz}; r < nums.size(); ++r) {
            product *= nums[r];

            while (product >= k) {
                product /= nums[l++];
            }

            res += r - l + 1;
        }

        return res;          
    }
};