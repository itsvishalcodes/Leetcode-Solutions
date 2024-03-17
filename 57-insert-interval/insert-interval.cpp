class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    intervals.push_back(newInterval);
    
    sort(intervals.begin(), intervals.end(), [](vector<int>& int1, vector<int>& int2) {
      return int1[0] <= int2[0];
    });
    ans.push_back(intervals[0]);

    int tPtr = 0;
    for(int i=1; i<intervals.size(); i++) {
      if(intervals[i][0] <= ans[tPtr][1]) {
        ans[tPtr][0] = min(ans[tPtr][0], intervals[i][0]);
        ans[tPtr][1] = max(ans[tPtr][1], intervals[i][1]);        
      } else {
        ans.push_back(intervals[i]);
        tPtr++;
      }
    }
    
    return ans;
  }
};