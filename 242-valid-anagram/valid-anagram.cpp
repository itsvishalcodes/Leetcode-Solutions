class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<vector<int>> freq(2, vector<int>(26, 0));

    for(auto i:s) freq[0][i-'a']++;
    for(auto i:t) freq[1][i-'a']++;

    for(int i=0; i<26; i++) {
      if(freq[0][i] != freq[1][i]) {
        return false;
      }
    }

    return true;
  }
};