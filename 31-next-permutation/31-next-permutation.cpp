class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    if(is_sorted(nums.begin(), nums.end(), greater<int>())) {
      reverse(nums.begin(), nums.end());
      return;
    }
    
    int inc;
    for(int i=nums.size()-2; i>=0; i--) {
      if(nums[i] < nums[i+1]) {
        inc = i;
        break;
      }
    }
    int justGreater;
    for(int i=nums.size()-1; i>inc; i--) {
      if(nums[i] > nums[inc]) {
        justGreater=i;
        break;
      }
    }
    swap(nums[inc], nums[justGreater]);
    reverse(nums.begin()+inc+1, nums.end());
    
    return;
  }
};