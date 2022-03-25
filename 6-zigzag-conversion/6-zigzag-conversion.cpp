class Solution {
public:
  string convert(string s, int numRows) {
    if(numRows == 1) return s;
    
    vector<string> zigzag(numRows, "");
    bool isGoingDown = true;
    int it = 0;
    string soln = "";
    
    for(auto i:s) {
      if(isGoingDown) {
        zigzag[it] += i;
        it++;
        if(it == numRows) {
          it = it-2;
          isGoingDown = false;
        }        
      }
      else {
        zigzag[it] += i;
        it--;
        if(it == -1) {
          it = 1;
          isGoingDown = true;
        }
      }
    }
    
    for(auto i:zigzag) soln += i;
    
    return soln;
  }
};