class Solution {
public:
  string customSortString(string order, string s) {
    vector<int> pos(26, 0);
    for(int i=0; i<order.size(); i++) {
      pos[order[i]-'a'] = (i+1);
    }

    sort(s.begin(), s.end(), [&pos](const char& c1, const char& c2) {
      return pos[c1-'a'] < pos[c2-'a'];
    });
    return s;
  }
};