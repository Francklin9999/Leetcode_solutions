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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;

        ListNode* curr{head};
        ListNode* next{head->next};
        ListNode* dummy = new ListNode();
        ListNode* prev{dummy};
        prev->next = curr;

        while (next) {
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            if (!next->next->next || !next->next->next->next) break;
            prev = curr;
            next = next->next->next->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};