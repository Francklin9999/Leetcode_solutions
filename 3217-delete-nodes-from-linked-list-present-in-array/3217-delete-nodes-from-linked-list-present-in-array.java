/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        if(head == null) return new ListNode();

        Set<Integer> set = new HashSet<>();

        for(int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }

        while(set.contains(head.val)) {
            head = head.next;
        }

        ListNode current = head;
        ListNode left = head;

        while(current != null) {
            if(set.contains(current.val)) {
                left.next = current.next;
                current = left.next;
                continue; 
            }
            left = current;
            current = current.next;
        }

        return head;
    }
}