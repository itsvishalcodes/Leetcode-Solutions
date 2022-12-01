class Solution {
public:
  bool halvesAreAlike(string s) {
    int idx=0;
    vector<int> cnt(2, 0);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    while(idx < s.size()/2) {
      if(s[idx]=='a' || s[idx]=='e' || s[idx]=='i' || s[idx]=='o' || s[idx]=='u') {
        cnt[0]++;
      }
      
      if(s[idx+s.size()/2]=='a' || s[idx+s.size()/2]=='e' || s[idx+s.size()/2]=='i' || s[idx+s.size()/2]=='o' || s[idx+s.size()/2]=='u') {
        cnt[1]++;
      }
      idx++;
    }
    
    if(cnt[0] == cnt[1]) return true;
    return false;
  }
};