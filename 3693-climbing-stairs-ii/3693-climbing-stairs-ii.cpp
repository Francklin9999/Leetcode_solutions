class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int last1{}, last2{}, last3{};
        int curr{};

        for (int i{0}; i < n; ++i) {
            curr = std::min({
                last1 + 1,
                i >= 1 ? last2 + 4 : INT_MAX,
                i >= 2 ? last3 + 9 : INT_MAX
            }) + costs[i];

            last3 = last2;
            last2 = last1;
            last1 = curr;
        }

        return curr;
    }
};