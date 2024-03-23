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
  void reorderList(ListNode* head) {
    stack<ListNode*> st;
    ListNode *slow=head, *fast=head, *itr=head;
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if(fast) slow = slow->next;
    itr = slow;
    while(itr) {
      st.push(itr);
      itr = itr->next;
    }
    itr = head;
    while(!st.empty()) {
      ListNode* nxt = itr->next;
      itr->next = st.top();
      itr->next->next = nxt;
      itr = nxt;
      st.pop();
    }
    itr->next = nullptr;
    return;
  }
};