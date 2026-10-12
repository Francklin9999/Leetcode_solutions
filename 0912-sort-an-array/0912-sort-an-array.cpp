class Solution {
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> tmp;
    tmp.reserve(high - low + 1);

    int i = low;
    int j = mid + 1;
    
    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) tmp.push_back(nums[i++]);
        else tmp.push_back(nums[j++]);
    }

    while (i <= mid) {
        tmp.push_back(nums[i++]);
    }

    while (j <= high) {
        tmp.push_back(nums[j++]);
    }

    for (auto k{0uz}; k < tmp.size(); ++k) {
        nums[low + k] = tmp[k];
    }
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);

    merge(nums, low, mid, high);
}

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> cp{nums};

        mergeSort(cp, 0, cp.size() - 1);
        return cp;    
    }
};