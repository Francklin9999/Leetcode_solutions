class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currMax = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        int temp;

        for (int i = arr.size() - 2; i >= 0; i--) {
            temp = arr[i];
            arr[i] = currMax;
            currMax = std::max(currMax, temp);
        }

        return arr;
    }
};