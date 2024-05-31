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
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;

        if (isBalanced(root.left) == false || isBalanced(root.right) == false) {
            return false;
        }

        int left = helper(root.left, 1);
        int right = helper(root.right, 1);

        if (Math.abs(left - right) > 1) return false;


        return true;
    }

    private int helper(TreeNode root, int depth) {
        if (root == null) return 0;

        return 1 + Math.max(helper(root.left, depth + 1), helper(root.right, depth + 1));
    }
}