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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *firstPtr=head, *secondSlow=head, *secondFast=head;
    int tempK = k;
    
    while(tempK--) {
      secondFast = secondFast->next;
    }
    while(secondFast) {
      secondSlow = secondSlow->next;
      secondFast = secondFast->next;
    }
    
    tempK = k-1;
    while(tempK--) {
      firstPtr = firstPtr->next;
    }
    
    int tmp = secondSlow->val;
    secondSlow->val = firstPtr->val;
    firstPtr->val = tmp;
    
    return head;
  }
};