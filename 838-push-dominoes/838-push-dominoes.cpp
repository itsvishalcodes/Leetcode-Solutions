class Solution {
public:
  // A bit help taken from Solution section (Code is not copied)
  string pushDominoes(string dominoes) {
    int currForce = 0;
    string soln = "";
    vector<int> l2r(dominoes.size(), 0), r2l(dominoes.size());
    
    for(int i=0; i<dominoes.size(); i++) {
      if(dominoes[i] == 'R') currForce = dominoes.size();
      if(dominoes[i] == 'L') currForce = 0;
      l2r[i] = max(0, currForce);
      currForce--;
    }
    
    
    currForce = 0;
    
    for(int i=dominoes.size()-1; i>=0; i--) {
      if(dominoes[i] == 'R') currForce = 0;
      if(dominoes[i] == 'L') currForce = -1*dominoes.size();
      r2l[i] = min(0, currForce);
      currForce++;
    }
    
    for(int i=0; i<dominoes.size(); i++) {
      if(l2r[i]+r2l[i] > 0) soln+="R";
      else if(l2r[i] + r2l[i] < 0) soln+="L";
      else soln+=".";
    }
    
    return soln;
  }
};