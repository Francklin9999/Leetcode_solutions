class Solution {
public:
    int maxArea(vector<int>& height) {
        int l{}, r = height.size() - 1, max{};

        while (l < r) {
            max = std::max(max, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) ++l;
            else --r;
        }

        return max;
    }
};