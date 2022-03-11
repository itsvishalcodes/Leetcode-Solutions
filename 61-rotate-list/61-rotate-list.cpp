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
  ListNode* rotateRight(ListNode* head, int k) {
    if(!head or !(head->next) or k==0) return head;
    
    ListNode *slow = head, *fast = head;
    int sz = 0;
    
    // get size
    while(fast) {
      sz++;
      fast = fast->next;
    }
    fast = head;
    
    if(k%sz==0) return head;
    
    k = k%sz;
    k = max(0, --k);
    while(k--) fast = fast->next;
    
    while(fast and fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    
    fast->next = head;
    fast = fast->next;
    
    while(fast->next != slow) fast = fast->next;
    
    fast->next = nullptr;
    
    return slow;
  }
};