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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        auto curr = dummy;
        int carry{};

        while (l1 || l2 || carry) {
            ListNode* next = new ListNode();
            curr->next = next;
            curr = next;
            int tmp{};

            if (l1) {
                tmp += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                tmp += l2->val;
                l2 = l2->next;
            }

            if (carry) {
                tmp += carry;
            }


            carry = tmp / 10;
            curr->val = tmp % 10;
        }

        return dummy->next;
    }
};