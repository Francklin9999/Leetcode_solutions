class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::size_t slow{};
        std::size_t fast{};

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
         } while (slow != fast);

        slow = 0;

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};