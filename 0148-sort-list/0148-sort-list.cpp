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
    if (head->next == nullptr) return head;
    
    int len{};
    ListNode* curr {head};
    while (curr != nullptr) {
        curr = curr->next;
        ++len;
    }

    curr = head;
    for (int i{}; i < (len / 2) - 1; ++i) {
        curr = curr->next;
    }

    auto tmp = curr;
    curr = curr->next;
    tmp->next = nullptr;

    ListNode* left = sort(head);
    ListNode* right = sort(curr);

    ListNode dummy(0, nullptr);
    curr = &dummy;

    while (left || right) {
        if (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next; 
            } else {
                curr->next = right;
                right = right->next;
            }
        } else if (left) {
            curr->next = left;
            left = left->next;
        } else {
            curr->next = right;
            right = right->next;
        }

        curr = curr->next;
    }

    return dummy.next;
}
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        return sort(head);
    }
};