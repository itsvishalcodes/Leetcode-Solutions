class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    unordered_map<int, bool> isPresent;
    
    for(auto i:nums) {
      isPresent[i] = true;
    }
    
    int toCheck=1;
    while(true) {
      if(isPresent[toCheck]) toCheck++;
      else return toCheck;
    }
  }
};