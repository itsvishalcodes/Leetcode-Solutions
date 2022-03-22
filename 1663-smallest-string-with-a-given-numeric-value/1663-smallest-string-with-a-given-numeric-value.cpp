class Solution {
public:
  string getSmallestString(int n, int k) {
    string soln = "";
    for(int i=0; i<n; i++) soln += 'a';
    
    k = k-n;
    int it = n-1;
    while(k>=26) {
      soln[it] = 'z';
      k = k-25;
      it--;
    }
    soln[it] = (char)('a' + k);
    
    return soln;
  }
};