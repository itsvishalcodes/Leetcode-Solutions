class Solution {
public:
  int getOnes(int n) {
    int totalOnes = 0;
    while(n) {
      n = n & (n-1);
      totalOnes++;
    }
    
    return totalOnes;
  }
  
  vector<int> countBits(int n) {
    vector<int> soln;
    
    for(int i=0; i<=n; i++) soln.push_back(getOnes(i));
    
    return soln;
  }
};