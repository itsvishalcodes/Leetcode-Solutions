class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    if(nums.size() < 3) return 0;
    
    int totalSubArrays = 0;
    vector<int> diff(nums.size()-1);
    for(int i=1; i<nums.size(); i++) diff[i-1] = nums[i] - nums[i-1];
    
    int curr = diff[0], tempLen, j;
    for(int i=0; i<diff.size(); ) {
      
      curr = diff[i];
      for(j = i+1; j<diff.size(); j++) {
        if(diff[i] != diff[j]) break;
      }
      
      tempLen = j-i;
      totalSubArrays += ( (tempLen*(tempLen-1))/2 );
      i = j;
    }
    
    return totalSubArrays;
  }
};