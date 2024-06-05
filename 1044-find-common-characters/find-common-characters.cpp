class Solution {
public:
  vector<string> commonChars(vector<string>& words) {
    vector<vector<int>> freq(words.size(), vector<int>(26, 0));
    vector<string> ans;

    for(int i=0; i<words.size(); i++) {
      for(auto j:words[i]) {
        freq[i][j-'a']++;
      }
    }

    for(int i=0; i<26; i++) {
      int mn = INT_MAX;
      for(int j=0; j<words.size(); j++) {
        mn = min(mn, freq[j][i]);
      }
      for(int j=0; j<mn; j++) {
        ans.push_back(string(1, 'a'+i));
      }
    }

    return ans;
  }
};