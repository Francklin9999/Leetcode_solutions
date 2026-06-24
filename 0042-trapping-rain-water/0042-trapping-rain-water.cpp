class Solution {
public:
    int trap(vector<int>& height) {
        int total{};

        int l = 0 ;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];
        
        while (l < r) {
            int tmp;
            if (maxL <= maxR) {
                maxL = std::max(maxL, height[++l]);
                tmp = std::min(maxR, maxL) - height[l];
            } else {
                maxR = std::max(maxR, height[--r]);
                tmp = std::min(maxR, maxL) - height[r];
            }

            total += tmp > 0 ? tmp : 0;
        }


        return total;
    }
};