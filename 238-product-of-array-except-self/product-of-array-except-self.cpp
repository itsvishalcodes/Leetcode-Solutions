class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> multPre(nums.size(), 1);
    vector<int> multSuf(nums.size(), 1);
    vector<int> ans(nums.size(), 1);

    for(int i=1; i<nums.size(); i++)
      multPre[i] = multPre[i-1] * nums[i-1];
    for(int i=nums.size()-2; i>=0; i--) 
      multSuf[i] = multSuf[i+1] * nums[i+1];

    for(int i=0; i<nums.size(); i++) 
      ans[i] = multPre[i] * multSuf[i];
    
    return ans;
  }
};