/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    var l = 0;
    var r = nums.length - 1;

    while (l <= r) {
        let mid = Math.floor((r + l) / 2);
        if (nums[mid] > target) {
            r = mid - 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            return mid;
        }
    };
    return -1; 

};