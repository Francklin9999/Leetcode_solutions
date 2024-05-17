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
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        int value = helper(root, target);
        return (value == 1) ? root : null;
    }

    public int helper(TreeNode root, int target) {
        if (root == null) return 0;

        if (root.left == null && root.right == null && root.val == target) {
            return -1;
        }

        if (helper(root.left, target) == -1) {
            root.left = null;
        }

        if (helper(root.right, target) == -1) {
            root.right = null;
        }

        if (root.left == null && root.right == null && root.val == target) {
            return -1;
        }

        return 1;
    }
}