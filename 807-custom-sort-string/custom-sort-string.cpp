class Solution {
public:
  string customSortString(string order, string s) {
    map<char, int> pos;
    for(int i=0; i<order.size(); i++) {
      pos[order[i]] = (i+1);
    }

    sort(s.begin(), s.end(), [&pos](const char& c1, const char& c2) {
      return pos[c1] < pos[c2];
    });
    return s;
  }
};