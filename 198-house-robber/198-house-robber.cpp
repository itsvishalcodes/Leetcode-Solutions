class Solution {
public:
  int totalAmount(vector<int>& nums, int idx, unordered_map<int, int>& dp) {
    // Base Case
    if(idx >= nums.size()) return 0;
    
    if(dp.find(idx) != dp.end()) return dp[idx];
    
    // 2 options in recursive case
    // 1. Rob the current house but then you can't rob the next house
    int house1 = nums[idx] + totalAmount(nums, idx+2, dp);
    // 2. Ignore the current house and rob the next one
    int house2 = totalAmount(nums, idx+1, dp);
    
    // We'll take max of it
    int totalEarning = max(house1, house2);
    
    dp[idx] = totalEarning;
    
    return dp[idx];
  }
  
  int rob(vector<int>& nums) {
    unordered_map<int, int> dp;
    return totalAmount(nums, 0, dp);
  }
};