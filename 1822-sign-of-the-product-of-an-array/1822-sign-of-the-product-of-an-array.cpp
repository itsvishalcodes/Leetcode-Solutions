class Solution {
public:
  int arraySign(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int NegCount=0;
    for(auto i:nums) {
      if(i <= 0) {
        if(i==0) return 0;
        NegCount++;
      }
    }
    
    if(NegCount%2) return -1;
    return 1;
  }
};