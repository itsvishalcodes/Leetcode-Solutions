class Solution {
public:
  vector<string> soln;
  
  void util(string s, int openable, int closable) {
    // Base Case
    if(openable==0 and closable==0) {
      soln.push_back(s);
      return;
    }
    
    // Recursive Case
    if(openable > 0) util(s+'(', openable-1, closable+1);
    if(closable > 0) util(s+')', openable, closable-1);
    
  }
  
  vector<string> generateParenthesis(int n) {
    util("", n, 0);
    
    return soln;
  }
};