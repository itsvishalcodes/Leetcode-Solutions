class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int lo=0, hi=nums.size()-1;
    int mid;
    
    while(lo<hi) {
      
      mid = (lo+hi)/2;
      // if(mid==nums.size()-1) return mid;
      // else if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]) return mid;
      if(nums[mid] > nums[mid+1]) hi=mid;
      else lo=mid+1;
    }
    return lo;
  }
};