class Solution {
public:
  string minRemoveToMakeValid(string s) {
    string soln = "";
    int score = 0;
    
    for(auto i:s) {
      if(i == ')' and score==0) {
        continue;
      }
      else if(i == ')') {
        soln += i;
        score--;
      }
      else if(i == '(') {
        soln += i;
        score++;
      }
      else {
        soln += i;
      }
    }
    
    if(!score) return soln;
    
    for(int i=soln.size()-1; i>=0 and score>0; i--) {
      if(soln[i] == '(') {
        soln.erase(soln.begin() + i);
        score--;
      }
    }
    return soln;
  }
};