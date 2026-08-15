class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int x = nums1.size();
        int y = nums2.size();

        int l{}, r{x};
        while (true) {
            int m1 = l + (r - l) / 2;
            int m2 = (x + y + 1) / 2 - m1;

            int left1 = m1 > 0 ? nums1[m1 - 1] : std::numeric_limits<int>::min();
            int left2 = m2 > 0 ? nums2[m2 - 1] : std::numeric_limits<int>::min();
            int right1 = m1 < x ? nums1[m1] : std::numeric_limits<int>::max();
            int right2 = m2 < y ? nums2[m2] : std::numeric_limits<int>::max();

            if (left1 <= right2 && left2 <= right1) {
                if ((x + y + 2) % 2 == 0) {
                    return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                } else{
                    return std::max(left1, left2);
                }
            } else if (left1 > right2) {
                r = m1 - 1;
            } else {
                l = m1 + 1;
            }
        }

        return 0.0;
    }
};