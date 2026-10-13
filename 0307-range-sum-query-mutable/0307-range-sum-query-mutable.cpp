class NumArray {
private:
    vector<int> tree;
    int l, r;
    
    void build(vector<int>& nums, int node, int low, int high) {
        if (low == high) {
            tree[node] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(nums, 2 * node, low, mid);
        build(nums, 2 * node + 1, mid + 1, high);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int idx, int val, int low, int high) {
        if (low == high) {
            tree[node] = val;
            return;
        }

        int mid = low + (high - low) /  2;

        if (idx <= mid) update(2 * node, idx, val, low, mid);
        else            update(2 * node + 1, idx, val, mid + 1, high);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int left, int right, int low, int high) {
        if (left <= low && high <= right) {
            return tree[node];
        }

        int sum{};

        int mid = low + (high - low) / 2;

        if (left <= mid) sum += query(2 * node, left, right, low, mid);
        if (right > mid) sum += query(2 * node + 1, left, right, mid + 1, high);

        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        tree.resize(4 * nums.size(), 0);
        l = 0;
        r = static_cast<int>(nums.size()) - 1;
        build(nums, 1, l, r);
    }
    
    void update(int index, int val) {
        update(1, index, val, l, r);
    }
    
    int sumRange(int left, int right) {
        return query(1, left, right, l, r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */