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
  bool isPalindrome(ListNode* head) {
    stack<ListNode*> st;
    ListNode* itr = head;
    while(itr) {
      st.push(itr);
      itr = itr->next;
    }
    itr = head;
    while(!st.empty()) {
      ListNode* tmp = st.top();
      st.pop();
      if(tmp->val != itr->val) return false;
      itr = itr->next;
    }
    return true;
  }
};