class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int sz = triangle.size();
    for(int i=sz-1; i>0; i--) {
      for(int j=0; j<triangle[i].size()-1; j++) {
        triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
      }
    }
    return triangle[0][0];
  }
};