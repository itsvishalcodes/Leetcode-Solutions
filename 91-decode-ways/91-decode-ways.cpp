class Solution {
public: 
  int totalWays(string& s, int idx, unordered_map<int, int>& dp) {
    // Return from memo
    if(dp.find(idx) != dp.end()) return dp[idx];
    
    // Base Case
    if(idx == s.size()) return 1;
    if(idx>s.size() or s[idx] == '0') return dp[idx] = 0;
    
    // Recursive Case    
    int twoDigitNum = ((s[idx]-'0')*10) + (s[idx+1]-'0');
    
    dp[idx] = totalWays(s, idx+1, dp);
    
    if(twoDigitNum <= 26) {
      dp[idx] += totalWays(s, idx+2, dp);
    }
    
    return dp[idx];
  }
  
  int numDecodings(string s) {
    unordered_map<int, int> dp;
    return totalWays(s, 0, dp);
  }
};