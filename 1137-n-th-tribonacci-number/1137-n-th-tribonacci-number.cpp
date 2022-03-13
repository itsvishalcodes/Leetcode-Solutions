class Solution {
public:
  int trib(int n, vector<int>& dp) {
    // Base Case
    if(n==0) return 0;
    if(n <= 2) return 1;
    
    // Recursive Case
    if(dp[n] != -1) return dp[n];
    
    return dp[n] = trib(n-1, dp) + trib(n-2, dp) + trib(n-3, dp);
        
  }
  
  int tribonacci(int n) {
    vector<int> dp(n+1, -1);
    return trib(n, dp);
  }
};