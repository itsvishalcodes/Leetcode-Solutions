class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowSize = matrix.size(), colSize = matrix[0].size();
    pair<int, int> initPos = { 0, colSize-1 };
    
    while(initPos.first < rowSize and initPos.second >= 0) {
      int i = initPos.first, j = initPos.second;
      
      if(matrix[i][j] == target) {
        return true;
      }
      else if(matrix[i][j] < target) {
        initPos.first++;
      }
      else {
        initPos.second--;
      }
    }
    
    return false;
  }
};