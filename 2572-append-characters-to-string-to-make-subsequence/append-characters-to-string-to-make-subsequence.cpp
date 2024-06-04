class Solution {
public:
  int appendCharacters(string s, string t) {
    int s_idx=0, t_idx=0;

    while(s_idx < s.size() && t_idx < t.size()) {
      while(s_idx < s.size() && s[s_idx] != t[t_idx]) {
        s_idx++;
      }

      if(s_idx < s.size() && s[s_idx] == t[t_idx]) {
        s_idx++; t_idx++;
      }
    }

    return t.size()-t_idx;
  }
};