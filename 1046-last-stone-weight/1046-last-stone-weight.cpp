class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    int tp1, tp2;
    priority_queue<int> pq;
    for(auto i:stones) {
      pq.push(i);
    }
    
    while(pq.size() > 1) {
      tp1 = pq.top(); pq.pop();
      tp2 = pq.top(); pq.pop();
      if(tp1 != tp2) {
        pq.push(tp1 - tp2);
      }
    }
    
    if(!pq.size()) return 0;
    return pq.top();
  }
};