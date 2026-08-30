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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start{list1};
        ListNode* end{list1};

        for (int i{}; i < a - 1; ++i) {
            start = start->next;
            end = end->next;
        }

        for (int i{a - 1}; i < b; ++i) {
            end = end->next;
        }

        auto old = start->next;
        start->next = list2;

        ListNode* last{list2};
        while (last->next) last = last->next;

        last->next = end->next;

        while (old != end) {
            auto tmp = old;
            old = old->next;
            delete tmp;
        }

        delete old;
        return list1;
    }
};