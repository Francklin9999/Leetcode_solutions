class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        auto n1 = std::count(nums1.begin(), nums1.end(), 0);
        auto n2 = std::count(nums2.begin(), nums2.end(), 0);

        auto curr1 = std::accumulate(nums1.begin(), nums1.end(), n1);
        auto curr2 = std::accumulate(nums2.begin(), nums2.end(), n2);

        if (!n1 && curr1 < curr2) return -1;
        if (!n2 && curr2 < curr1) return -1;

        return std::max(curr1, curr2);
    }
};