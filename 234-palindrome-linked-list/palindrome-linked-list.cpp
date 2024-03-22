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
  bool isPalindrome(ListNode* head, string s="") {
    ListNode *slow=head, *fast=head, *behindSlow=head;
    while(fast && fast->next) {
      behindSlow = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    if(fast) {
      slow = slow->next;
    }
    behindSlow->next = nullptr;
    ListNode *itr = head, *prev = nullptr;
    while(itr) {
      ListNode* tmp = itr->next;
      itr->next = prev;
      prev = itr;
      itr = tmp;
    }
    while(behindSlow && slow) {
      if(slow->val != behindSlow->val) {
        return false;
      }
      slow = slow->next;
      behindSlow = behindSlow->next;
    }
    return true;
  }
};