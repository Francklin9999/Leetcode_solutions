class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> set;

        for (auto i = 0uz; i < nums1.size(); ++i) {
            set.insert(nums1[i]);
        }

        for (auto i = 0uz; i < nums2.size(); ++i) {
            if (set.find(nums2[i]) != set.end()) {
                res.push_back(nums2[i]);
                set.erase(nums2[i]);
            }
        }

        return res;
    }
};