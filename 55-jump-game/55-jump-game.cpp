class Solution {
public:
  bool canJump(vector<int>& nums) {
    if(nums.size()<=1) return true;
    
    if(nums[0] == 0) return false;
    
    int maxReachableIndex = nums[0];
    int it = 1;
    
    while(it <= maxReachableIndex) {
      if(maxReachableIndex >= nums.size()-1) {
        return true;
      }
      maxReachableIndex = max(maxReachableIndex, it + nums[it]);
      
      it++;
    }
    
    return false;
  }
};