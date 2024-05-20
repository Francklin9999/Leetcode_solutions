class Solution {
    public int trap(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int maxL = height[l];
        int maxR = height[r];
        int sum = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (maxL - height[l] > 0) {
                    sum += maxL - height[l];
                }
                l++;
                maxL = Math.max(maxL, height[l]);
                
            }
            else {
                if (maxR - height[r] > 0) {
                    sum += maxR - height[r];
                }
                r--;
                maxR = Math.max(maxR, height[r]);
            }

        }
        return sum;
    }
}