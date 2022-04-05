class Solution {
public:
  void util(vector<int>& nums, int idx, vector<vector<int>>& soln, vector<int> tmp) {
    if(idx == nums.size()) {
      soln.push_back(tmp);
      return;
    }
    
    util(nums, idx+1, soln, tmp);
    
    tmp.push_back(nums[idx]);
    util(nums, idx+1, soln, tmp);
  }
  
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> soln;
    util(nums, 0, soln, vector<int>());
    
    return soln;
  }
};