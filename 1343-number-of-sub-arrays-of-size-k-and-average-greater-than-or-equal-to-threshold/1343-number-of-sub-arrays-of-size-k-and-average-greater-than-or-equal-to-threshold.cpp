class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ways = 0;
        int currSum = 0;
        int l = 0;
        int r = 0;

        for (; r < k - 1; r++) {
            currSum += arr[r];
        }

        while (r < arr.size()) {
            currSum += arr[r];
            if ((currSum / (r - l + 1)) >= threshold) {
                ways++;
            }
            currSum -= arr[l];
            r++;
            l++;
        }

        return ways;
    }
};