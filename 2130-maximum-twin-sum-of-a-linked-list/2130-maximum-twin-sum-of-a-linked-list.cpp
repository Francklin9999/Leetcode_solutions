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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        fast = slow;

        while (slow) {
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }

        slow = head;
        fast = prev;

        int maxSum = 0;

        while (fast) {
            maxSum = std::max(maxSum, slow->val + fast->val);
            slow = slow->next;
            fast = fast->next;
        }

        return maxSum;
    }
};