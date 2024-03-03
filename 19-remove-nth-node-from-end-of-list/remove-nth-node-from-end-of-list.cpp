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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fastPtr = head, *slowPtr = head;
    while(n--) {
      fastPtr = fastPtr->next;
    }
    while(fastPtr != nullptr && fastPtr->next != nullptr) {
      fastPtr = fastPtr->next;
      slowPtr = slowPtr->next;
    }

    if(fastPtr == nullptr)
      return head->next;
    else
      slowPtr->next = slowPtr->next->next;
    return head;
  }
};