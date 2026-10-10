class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int curr_seq{1};
        int max_seq{0};

        for (int num : set) {
            if (set.count(num - 1)) continue;

            while (set.count(num + curr_seq)) {
                ++curr_seq;
            }

            max_seq = std::max(max_seq, curr_seq);
            curr_seq = 1;
        }

        return max_seq;
    }
};