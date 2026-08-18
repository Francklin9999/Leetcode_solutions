class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        int result{};

        for (auto task : nums) ++count[task];

        for (auto it : count) {
            if (it.second < 2) return -1;
            result += (it.second + 2) / 3;
        }

        return result; 
    }
};