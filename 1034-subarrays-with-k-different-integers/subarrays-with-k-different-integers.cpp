class Solution {
public:
  int helper(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int left=0, right=0, ans=0;
    while(right < nums.size()) {
      freq[nums[right]]++;
      while(freq.size() > k) {
        freq[nums[left]]--;
        if(freq[nums[left]] == 0) {
          freq.erase(nums[left]);
        }
        left++;
      }
      ans += (right - left + 1);
      right++;
    }
    return ans;
  }
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helper(nums, k) - helper(nums, k-1);
  }
};