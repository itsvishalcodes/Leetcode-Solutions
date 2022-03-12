/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* createNewNode(unordered_map<Node*, Node*>& oldToNew, Node* old) {
    // Base Case
    if(!old) {
      return nullptr;
    }
    
    // Recursive Case
    Node* newNode;
    if(oldToNew.find(old) != oldToNew.end()) {
      newNode = oldToNew[old];
    }
    else {
      newNode = new Node(old->val);
      oldToNew[old] = newNode;
      newNode -> next = createNewNode(oldToNew, old->next);
      newNode -> random = createNewNode(oldToNew, old->random);
    }
    
    return newNode;
  }
  
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> oldToNew;
    
    Node *it = head, *nextPtr, *newHead = new Node(0);
    // newHead is initially pointing to dummy node.
    nextPtr = newHead;
    
    
    nextPtr -> next = createNewNode(oldToNew, it);
      
    
    return newHead -> next;    
  }
};