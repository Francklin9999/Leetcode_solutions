class NumArray {
private:
    vector<int> tree;
    int l, r;

    void build(vector<int>& nums, int low, int high, int idx) {
        if (low == high) {
            tree[idx] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(nums, low, mid, 2 * idx);
        build(nums, mid + 1, high, 2 * idx + 1);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    void update(int idx, int val, int low, int high, int pos) {
        if (low == high) {
            tree[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (pos <= mid) update(2 * idx, val, low, mid, pos);
        else            update(2 * idx + 1, val, mid + 1, high, pos);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    int query(int idx, int low, int high, int left, int right) {
        if (left <= low && high <= right) {
            return tree[idx];
        }

        int sum{};
        int mid = low + (high - low) / 2;

        if (left <= mid) sum += query(2 * idx, low, mid, left, right);
        if (right > mid) sum += query(2 * idx + 1, mid + 1, high, left, right);

        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        tree.resize(4 * nums.size());
        l = 0;
        r = nums.size() - 1;
        build(nums, l, r, 1);
    }
    
    void update(int index, int val) {
        update(1, val, l, r, index);
    }
    
    int sumRange(int left, int right) {
        return query(1, l, r, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */