class Solution {
public:
  int totalWays(int n, vector<int>& dp) {
    // Base Case
    if(n <= 2) return n;
    
    // Recursive Case
    if(dp[n] != -1) return dp[n];
    
    dp[n] = totalWays(n-1, dp) + totalWays(n-2, dp);
    return dp[n];
  }
  
  int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return totalWays(n, dp);
  }
};