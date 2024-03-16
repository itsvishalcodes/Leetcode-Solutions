class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sm = 0, ans=0;

    for(int i=0; i<nums.size(); i++) {
      if(nums[i] == 1) sm++;
      else sm--;
      if(sm == 0) ans = i+1;
      if(mp.find(sm) != mp.end()) {
        ans = max(ans, i - mp[sm]);
      } else {
        mp[sm] = i;
      }
    }    

    return ans;
  }
};