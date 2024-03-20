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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    int tmp = b-a;
    ListNode* hd = list1;
    while(--a) {
      list1 = list1->next;
    }
    ListNode* ahead = list1->next;
    list1->next = list2;
    while(tmp-- >= 0) {
      ahead = ahead->next;
    }
    while(list2 && list2->next) {
      list2 = list2->next;
    }
    list2->next = ahead;
    return hd;
  }
};