class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
      int num = nums[i];
      while(num >= 1 && num <= nums.size() && nums[num-1] != num) {
        swap(nums[num-1], nums[i]);
        num = nums[i];
      }
    }

    for(int i=0; i<nums.size(); i++) {
      if(nums[i] != i+1) return i+1;
    }

    return nums.size()+1;
  }
};