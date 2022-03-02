class Solution {
public:
  bool isSubsequence(string s, string t) {
    char curr;
    int i=0,j=0;
    
    while(i<s.size()) {
      char curr = s[i];
      
      if(j >= t.size()) return false;
      
      while(j<t.size()) {
        if(t[j] == curr) {
          i++;
          j++;
          goto outer;
        }
        j++;
      }
      
      outer:;
    }
    
    return true;
  }
};