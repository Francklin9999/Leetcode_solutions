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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        vector<ListNode*> merged;

        for (int i = 0; i < lists.size(); i += 2) {
            if (i + 1 < lists.size()) {
                merged.push_back(merge2Lists(lists[i], lists[i + 1]));
            } else {
                merged.push_back(lists[i]);
            }
        }

        while (merged.size() > 1) {
            vector<ListNode*> next;
            for (int i = 0; i < merged.size(); i += 2) {
                if (i + 1 < merged.size()) {
                    next.push_back(merge2Lists(merged[i], merged[i + 1]));
                } else {
                    next.push_back(merged[i]);
                }
            }

            merged = next;
        }

        return merged[0];
    }

    ListNode* merge2Lists(ListNode* root1, ListNode* root2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (root1 || root2) {
            if (root1 && root2) {
                if (root1->val <= root2->val) {
                    curr->next = root1;
                    root1 = root1->next;
                } else {
                    curr->next = root2;
                    root2 = root2->next;
                }
            } else if (root1) {
                curr->next = root1;
                root1 = root1->next;
            } else {
                curr->next = root2;
                root2 = root2->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};