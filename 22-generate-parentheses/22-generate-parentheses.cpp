class Solution {
public:
  void util(string& curr, vector<string>& soln, int openable, int closeable) {
    // Base Case
    if(openable==0 and closeable==0) {
      soln.push_back(curr);
      return;
    }
    
    // Recursive Case
    if(openable > 0) {
      curr = curr+'(';
      util(curr, soln, openable-1, closeable);
      // Backtracking Step below
      curr.pop_back();
    }
    
    if(openable < closeable) {
      curr = curr + ')';
      util(curr, soln, openable, closeable-1);
      // Backtrack
      curr.pop_back();
    }
  }
  
  vector<string> generateParenthesis(int n) {
    vector<string> soln;
    string curr = "";
    util(curr, soln, n, n);
    
    return soln;
  }
};