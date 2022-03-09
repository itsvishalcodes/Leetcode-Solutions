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
  ListNode* deleteDuplicates(ListNode* head) {
    // Create a Sentinel Head
    ListNode *sentinelHead = new ListNode(-101, head);
    
    if(!head) return nullptr;
  
    ListNode *slow = sentinelHead, *fast = head;
    bool flag;
    while(fast) {
      flag = false;
      
      while(fast->next and fast->val == fast->next->val) {
        flag = true;
        fast = fast->next;
      }
      if(flag) slow->next = fast->next;
      if(!flag)
        slow = slow->next;
      
      fast = fast->next;
    }
    
    return sentinelHead->next;
  }
};