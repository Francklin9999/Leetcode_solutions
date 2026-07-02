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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode dummy{0, head};
        ListNode* before{&dummy};
        ListNode* after{head};
        ListNode* first{nullptr};
        ListNode* prev{nullptr};
        ListNode* curr{nullptr};
        ListNode* next{nullptr};

        int i = 0;

        for (i = 1; i < left; ++i) {
            after = after->next;
            before = before->next;
        }
        curr = after;

        for (; i < right; ++i) {
            after = after->next;
        }
        after = after->next;

        first = curr;
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (next != after) ;

        before->next = prev;
        first->next = after;

        return dummy.next;
    }
};