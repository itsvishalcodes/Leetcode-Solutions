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
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* itr = dummy;

    while (itr) {
        int sm = 0;
        ListNode* nxt = itr->next;
        while (nxt) {
            sm += nxt->val;
            if (sm == 0) {
                itr->next = nxt->next;
            }
            nxt = nxt->next;
        }
        itr = itr->next;
    }
    return dummy->next;
  }
};