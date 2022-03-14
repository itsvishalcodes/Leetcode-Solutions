class Solution {
public:
  int findMin(vector<int>& nums) {
    int possibleMin = min(nums[0], nums[nums.size()-1]);
    
    int lo = 1, hi = nums.size()-2, mid;
    while(lo <= hi) {
      mid = (lo+hi)/2;
      if(nums[mid] <= possibleMin) {
        possibleMin = nums[mid];
        hi = mid-1;
      }
      else if(nums[mid] > possibleMin) {
        lo = mid+1;
      }
    }
    
    return possibleMin;
  }
};