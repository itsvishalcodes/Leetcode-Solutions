class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, vector<int>> numToIdxAndFreq;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++) {
      int toFind = target - nums[i];
      numToIdxAndFreq[nums[i]].push_back(i);

      if(numToIdxAndFreq[toFind].size() >= 1) {
        if(toFind == nums[i] && numToIdxAndFreq[toFind].size()==1) {
          continue;
        }
        
        if(toFind == nums[i]) {
          ans.push_back(numToIdxAndFreq[toFind][0]);
          ans.push_back(numToIdxAndFreq[toFind][1]);
        } else {
          ans.push_back(numToIdxAndFreq[nums[i]][0]);
          ans.push_back(numToIdxAndFreq[toFind][0]);
        }
        break;
      }
    }
    return ans;
  }
};