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
  ListNode* reverseList(ListNode* head) {
    if(!head) return nullptr;
    stack<ListNode*> st;
    ListNode* itr = head;
    while(itr) {
      st.push(itr);
      itr = itr->next;
    }
    ListNode* newHead = st.top();
    itr = newHead;
    st.pop();
    while(!st.empty()) {
      itr->next = st.top();
      itr = itr->next;
      st.pop();
    }
    itr->next = nullptr;
    return newHead;
  }
};