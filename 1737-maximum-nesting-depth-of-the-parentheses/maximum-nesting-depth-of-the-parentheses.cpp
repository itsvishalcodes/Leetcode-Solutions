class Solution {
public:
  int maxDepth(string s) {
    int ans = 0, tmpDepth = 0;
    for(auto i:s) {
      if(i == '(') tmpDepth++;
      else if(i == ')') tmpDepth--;
      ans = max(ans, tmpDepth); 
    }
    return ans;
  }
};