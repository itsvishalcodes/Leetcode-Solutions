class Solution {
public:
  int scoreOfParentheses(string s) {
    
    int totalScore = 0, n=0;
    bool flag = false;
    
    for(int i=0; i<s.size(); i++) {
      // n = -1;
      flag = false;
      while(i<s.size() and s[i] == '(') {
        n++;
        i++;
        flag = true;
      }
      n--;
      if(flag) {
        totalScore += pow(2,n);
      }
    }
    
    return totalScore;
  }
};