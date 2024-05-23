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

    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
    int k;
    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        helper(root);
        return maxHeap.peek();
    }

    private void helper(TreeNode root) {
        if (root == null) return;

        maxHeap.add(root.val);
        if (maxHeap.size() > k) maxHeap.poll();

        helper(root.left);
        helper(root.right);
        return;
    }
}