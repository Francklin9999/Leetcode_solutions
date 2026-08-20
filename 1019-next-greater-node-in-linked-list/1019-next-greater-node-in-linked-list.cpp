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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;

        stack<pair<int, int>> stack;

        int i{};
        while (head != nullptr) {
            res.push_back(0);

            while (!stack.empty() && head->val > stack.top().first) {
                res[stack.top().second] = head->val;
                stack.pop();
            }

            stack.emplace(pair<int, int>(head->val, i));

            ++i;
            head = head->next;
        }

        return res;
    }
};