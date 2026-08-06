class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> queue;

        for (auto i = 0uz; i < k - 1; ++i) {
            queue.emplace(nums[i], i);
        }

        for (auto i = k - 1; i < nums.size(); ++i) {
            queue.emplace(nums[i], i);

            while (i - queue.top().second >= k) {
                queue.pop();
            }

            res.push_back(queue.top().first);
        }

        return res;
    }
};