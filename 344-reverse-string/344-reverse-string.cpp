class Solution {
public:
  void reverseString(vector<char>& s) {
    int n=s.size()-1;
    for(int i=0; i<s.size()/2; i++) {
      swap(s[i], s[n-i]);
    }
  }
};