/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

ListNode* sort(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* slow{head};
    ListNode* fast{head->next};
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    auto tmp = slow;
    slow = slow->next;
    tmp->next = nullptr;

    ListNode* left = sort(head);
    ListNode* right = sort(slow);

    ListNode dummy(0, nullptr);
    slow = &dummy;

    while (left && right) {
        if (left->val < right->val) {
            slow->next = left;
            left = left->next; 
        } else {
            slow->next = right;
            right = right->next;
        }

        slow = slow->next;
    }

    if (left || right)
        slow->next = left ? left : right;

    return dummy.next;
}
public:
    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};