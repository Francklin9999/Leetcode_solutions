class NumArray {
vector<int> nums;
vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        prefix.reserve(nums.size());
        prefix[0] = 0;
        for (auto i = 1uz; i < nums.size(); ++i) {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }

    }
    
    int sumRange(int left, int right) {
        return (prefix[right] - prefix[left]) + nums[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */