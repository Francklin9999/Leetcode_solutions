class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [] (int a, int b) {
            return a > b;
        };
        std::priority_queue<
        int,
        vector<int>,
        decltype(cmp)
        > heap;

        for (auto i = 0uz; i < nums.size(); ++i) {
            heap.push(nums[i]);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        return heap.top();
    }
};