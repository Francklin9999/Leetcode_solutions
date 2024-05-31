/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        helper(root, 0);
        return max;
    }

    private int helper(TreeNode root, int _max) {
        if (root == null) return 0;

        int left = helper(root.left, _max);
        int right = helper(root.right, _max);

        _max = root.val + Math.max(left, right);

        int localmax = Math.max(Math.max(Math.max(left, right), left + right + root.val), max);
        if (localmax != 0) max = localmax;
        else max = Math.max(max, _max);

        return (_max > 0) ? _max : 0;
    }
}