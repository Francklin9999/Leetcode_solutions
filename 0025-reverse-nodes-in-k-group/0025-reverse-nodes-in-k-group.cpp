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

    ListNode* reverseK(ListNode* head, ListNode* end) {
        ListNode* prev{head};
        ListNode* curr{head->next};
        prev->next = nullptr;

        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = head;
        ListNode* curr = new ListNode(0, head);
        auto t = curr;
        ListNode* next{head};

        for (int i{}; i < k - 1 && dummy; ++i) {
            dummy = dummy->next;
        }

        if (!dummy) return head;

        while (next) {
            for (int i{}; i < k - 1 && next; ++i) {
                next = next->next;
            }

            if (next) {
                auto old = curr->next;
                auto tmp = next->next;
                ListNode* newHead = reverseK(curr->next, next->next); 
                curr->next = newHead;
                old->next = tmp;
                curr = old;
                next = tmp;
            }
        }

        delete t;
        return dummy;
    }
};