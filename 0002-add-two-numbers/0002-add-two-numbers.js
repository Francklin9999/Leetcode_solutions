/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var curr = new ListNode();
    var anw = curr;
    var counter = 0;

    while (l1 != null || l2 != null) {
        let next = new ListNode(counter);
        counter = 0;
        if (l1 != null) {
            next.val += l1.val;
            l1 = l1.next;
        };
        if (l2 != null) {
            next.val += l2.val;
            l2 = l2.next;
        };
        if (next.val >= 10) {
            next.val = next.val % 10;
            counter++;
        };
        curr.next = next;
        curr = curr.next;
    };
    if (counter != 0) {
        curr.next = new ListNode(counter);
    };
    return anw.next;
    };