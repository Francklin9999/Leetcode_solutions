class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int arr[3] = {0, 0, INT_MIN};
        bool flag{true};

        for (auto i{0uz}; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                arr[0] = arr[1];
                arr[1] = 0;
                flag = false;
            } else {
                arr[0] = arr[0] + 1;
                arr[1] = arr[1] + 1;
            }

            arr[2] = std::max({arr[0], arr[1], arr[2]});
        }

        return arr[2] - flag;
    }
};