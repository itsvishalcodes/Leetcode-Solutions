class Solution {
public:
  int fibonacci(int n, vector<int>& dp) {
    // Base Case
    if(n < 2) return n;
    
    // Recursive Case
    if(dp[n] != -1) return dp[n];
    
    return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
  }
  
  int fib(int n) {
    vector<int> dp(n+1, -1);
    return fibonacci(n, dp);
  }
};