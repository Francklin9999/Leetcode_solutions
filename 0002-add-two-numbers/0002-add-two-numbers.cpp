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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev{nullptr};
        ListNode* next{head};
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto first = l1;
        auto second = l2;
        ListNode* head = nullptr;

        int remainder{0};
        int curr{0};
        while (first || second || remainder) {
            curr = remainder;

            if (first) {
                curr += first->val;
                first = first->next;
            }

            if (second) {
                curr += second->val;
                second = second->next;
            }

            remainder = curr / 10;

            head = new ListNode(curr % 10, head);
        }

        return reverse(head);
    }
};