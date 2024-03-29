class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {
    int mx = *max_element(nums.begin(), nums.end());
    int mxFreq = 0, left = 0, right = 0;
    long long ans = 0;
    while(right < nums.size()) {
      if(nums[right++] == mx) mxFreq++;
      while(mxFreq >= k) {
        if(nums[left++] == mx) mxFreq--;
      }
      ans += left;
    }
    return ans;
  }
};