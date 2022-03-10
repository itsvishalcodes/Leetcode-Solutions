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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    
    ListNode *it1=l1, *it2=l2;
    ListNode *sentinelHead = new ListNode(0, nullptr), *itSum = sentinelHead;
    
    while(it1 and it2) {
      itSum->next = new ListNode((it1->val + it2->val + carry)%10, nullptr);
      if((it1->val + it2->val + carry) >= 10) carry = 1;
      else carry = 0;
      it1 = it1->next;
      it2 = it2->next;
      itSum = itSum->next;
    }
    
    while(it1) {
      itSum->next = new ListNode((it1->val + carry)%10, nullptr);
      if((it1->val + carry) >= 10) carry = 1;
      else carry = 0;
      it1 = it1->next;
      itSum = itSum->next;
    }
    
    while(it2) {
      itSum->next = new ListNode((it2->val + carry)%10, nullptr);
      if((it2->val + carry) >= 10) carry = 1;
      else carry = 0;
      it2 = it2->next;
      itSum = itSum->next;
    }
    
    if(carry) {
      itSum->next = new ListNode(1, nullptr);
      carry = 0;
    }
    
    return sentinelHead -> next;
  }
};