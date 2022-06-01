class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    int rnSum=0;
    for(int i=0; i<nums.size(); i++) {
      nums[i] = nums[i]+rnSum;
      rnSum = nums[i];
    }
    return nums;
  }
};