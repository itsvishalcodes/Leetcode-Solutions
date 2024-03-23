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
    ListNode *slow=head, *fast=head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *itr1=head, *itr2=slow->next, *prev = nullptr;
    slow->next = nullptr;
    while(itr2) {
      ListNode *tmp = itr2->next;
      itr2->next = prev;
      prev = itr2;
      itr2 = tmp;
    }
    itr2 = prev;
    
    ListNode *itr1Tmp=itr1, *itr2Tmp=itr2; 
    while(itr1) {
      itr1Tmp = itr1->next;
      if(itr2) {
        itr2Tmp = itr2->next;
        itr2->next = itr1->next;
      }
      itr1->next = itr2;
      itr1 = itr1Tmp;
      itr2 = itr2Tmp;
    }

    return;
  }
};