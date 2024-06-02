class Solution {
public:
    void reverseString(vector<char>& s) {
      int slow=0, fast=s.size()-1;
      while(slow < fast) {
        swap(s[slow], s[fast]);
        slow++; fast--;
      }
      return;
    }
};