class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res1{};
        int res2{};

        for (int n : nums) {
            res1 ^= n;
        }

        for (auto i = 0uz; i <= nums.size(); ++i) {
            res2 ^= i;
        }

        return (res1 ^ res2);
    }
};