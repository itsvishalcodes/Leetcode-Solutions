class Solution {
public:
  void util(vector<int>& nums, int idx, vector<vector<int>>& soln, set<vector<int>>& hasAppeared, vector<int> t) {
    if(idx == nums.size()) {
      sort(t.begin(), t.end());
      if(hasAppeared.find(t) == hasAppeared.end()) {
        hasAppeared.insert(t);
        soln.push_back(t);
      }
      return;
    }
    
    util(nums, idx+1, soln, hasAppeared, t);
    t.push_back(nums[idx]);
    util(nums, idx+1, soln, hasAppeared, t);
  }
  
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> hasAppeared;
    vector<vector<int>> soln;
    
    util(nums, 0, soln, hasAppeared, vector<int>());
    
    return soln;
  }
};