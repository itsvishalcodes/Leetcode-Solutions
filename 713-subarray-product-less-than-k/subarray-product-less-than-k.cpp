class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k <= 1) return 0;

    int ans=0, mult=1, left=0, right=0;

    while(right < nums.size()) {
      mult *= nums[right];
      while(mult >= k) {
        mult /= nums[left];
        left++;
      }
      ans += (right-left+1);
      right++;
    }

    return ans;
  }
};