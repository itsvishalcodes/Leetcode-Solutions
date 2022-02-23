/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    
    if(!node) return nullptr;
    
    unordered_map<Node*, Node*> isCreated;
    unordered_map<Node*, bool> isVisited;
    queue<Node*> q;
    q.push(node);
    
    while(q.size()) {
      Node* front = q.front();
      q.pop();
      
      if(isVisited[front]) continue;
      
      if(isCreated.find(front)==isCreated.end()) {
        isCreated[front] = new Node(front->val);
      }
      
      for(int i=0; i<(front->neighbors).size(); i++) {
        if(!isCreated[(front->neighbors)[i]]) {
          isCreated[(front->neighbors)[i]] = new Node((front->neighbors)[i] -> val);
        }
        isCreated[front]->neighbors.push_back( isCreated[(front->neighbors)[i]] );
        q.push((front->neighbors)[i]);
      }
      
      isVisited[front] = true;
    }
    
    return isCreated[node];
  }
};