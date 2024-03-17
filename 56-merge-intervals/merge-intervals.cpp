class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
      return a[0] < b[0];
    });
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++) {
      int sz = ans.size();
      if(intervals[i][0] <= ans[sz-1][1]) {
        ans[sz-1][1] = max(intervals[i][1], ans[sz-1][1]);
      } else {
        ans.push_back(intervals[i]);
      }
    }
    return ans;
  }
};