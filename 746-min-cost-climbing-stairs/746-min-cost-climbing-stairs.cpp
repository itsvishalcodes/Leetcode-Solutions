class Solution {
public:
  int minCost(int idx, vector<int>& cost, vector<int>& dp) {
    // Base Case
    if(idx >= cost.size()) {
      return 0;
    }
    
    if(dp[idx] != -1) return dp[idx];
    
    return dp[idx] = cost[idx] + min(minCost(idx+1, cost, dp), minCost(idx+2, cost, dp));
    
  }
  
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1, -1);
    return min(minCost(0, cost, dp), minCost(1, cost, dp));
  }
};