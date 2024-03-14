class Solution {
public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    int ans = 0, currSm = 0;
    map<int, int> freqTable;
    for(auto i:nums) {
      currSm += i;
      if(currSm == goal) {
        ans++;
      }
      ans += freqTable[currSm - goal];
      freqTable[currSm]++;
    }
    return ans;
  }
};