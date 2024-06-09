class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    map<int, int> magFreq;
    for(auto c:magazine) {
      magFreq[c]++;
    }
    for(auto c:ransomNote) {
      if(magFreq[c] == 0) return false;
      magFreq[c]--;
    }
    return true;
  }
};