class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> pq;
    vector<int> soln;
    
    for(auto i:nums)
      freq[i]++;
    
    for(auto i:freq)
      pq.push({i.second, i.first});
    
    while(k--) {
      soln.push_back(pq.top().second);
      pq.pop();
    }
    
    return soln;
  }
};