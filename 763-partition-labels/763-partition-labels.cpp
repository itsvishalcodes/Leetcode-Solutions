class Solution {
public:
  vector<int> partitionLabels(string s) {
    unordered_map<char, int> getLastIndex;
    vector<int> soln;
    
    for(int i=s.size()-1; i>=0; i--) {
      if(getLastIndex.find(s[i]) == getLastIndex.end()) 
        getLastIndex[s[i]] = i;
    }
    
    int start=0, end, it=0;
    
    while(start < s.size()) {
      end = getLastIndex[s[it]];
      
      while(it < end) {
        if(getLastIndex[s[it]] > end) 
          end = getLastIndex[s[it]];
        it++;
      }
      soln.push_back(end-start+1);
      
      start = end+1;
      it = start;
    }
    
    return soln;
  }
};