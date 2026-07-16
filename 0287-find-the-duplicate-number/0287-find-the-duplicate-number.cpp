class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::size_t slow{0}, fast{0};

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};