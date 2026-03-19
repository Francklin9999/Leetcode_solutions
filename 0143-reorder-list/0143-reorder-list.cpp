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
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* curr = second;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        first = head->next;
        second = prev;
        curr = head;

        while (first || second) {
            if (second) {
                curr->next = second;
                second = second->next;
                curr = curr->next;
            }

            if (first) {
                curr->next = first;
                first = first->next;
                curr = curr->next;
            }
        }
    }
};