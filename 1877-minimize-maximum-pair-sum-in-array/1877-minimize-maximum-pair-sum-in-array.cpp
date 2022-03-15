class Solution {
public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int left = 0, right = nums.size()-1;
    while(left < right) {
      nums[left] = nums[left] + nums[right];
      left++;
      right--;
    }
    
    return *max_element(nums.begin(), nums.begin()+(nums.size()/2));
  }
};