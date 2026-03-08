/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* quick = head;

        while (quick != NULL && quick->next != NULL) {
            slow = slow->next;
            quick = quick->next->next;
            if (slow == quick) return true;
        }

        return false;
    }
};