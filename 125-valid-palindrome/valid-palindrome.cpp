class Solution {
public:
  bool isValidChar(char c) {
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) {
      return true;
    }
    return false;
  }

  char getLower(char c) {
    if(c>='A' && c<='Z') {
      return c-('A'-'a');
    }
    return c;
  }

  bool isPalindrome(string s) {
    int left=0, right=s.size()-1;

    while(left < right) {
      if(!isValidChar(s[left])) {
        left++; continue;
      }
      if(!isValidChar(s[right])) {
        right--; continue;
      }

      if(getLower(s[left]) != getLower(s[right])) {
        return false;
      }
      left++; right--;
    }

    return true;
  }
};