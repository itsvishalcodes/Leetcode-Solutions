class Solution {
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
      long long ans = 0, toSub = -1, minTemp = -1, maxTemp = -1;

      for (int i = 0; i < nums.size(); i++) {
          if (nums[i] < minK || nums[i] > maxK) toSub = i;
          if (nums[i] == minK) minTemp = i;
          if (nums[i] == maxK) maxTemp = i;
          ans += max(0LL, min(minTemp, maxTemp) - toSub);
      }
      return ans;
  }
};