class Solution {
public:
  int robOrNot(vector<int>& nums, int idx, vector<int>& dp) {
    if(idx >= nums.size()) return 0;
    
    // Either Rob This House or Rob the next one
    if(dp[idx] != -1) return dp[idx];
    
    int currentHouse = nums[idx] + robOrNot(nums, idx+2, dp);
    int nextHouse = robOrNot(nums, idx+1, dp);
    
    return dp[idx] = max(currentHouse, nextHouse);
  }
  
  int rob(vector<int>& nums) {
    vector<int> dp(nums.size()+1, -1);
    return robOrNot(nums, 0, dp);
  }
};