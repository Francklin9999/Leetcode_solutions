/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var l = 0;
    var r = height.length - 1;
    var max = 0;

    while (l <= r) {
        max = Math.max(max, Math.min(height[l], height[r]) * (r - l));
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        } 
    };
    return max;
};