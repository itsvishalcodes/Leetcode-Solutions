class Solution {
public:
  int maxArea(vector<vector<int>>& grid, int row, int col) {
    int rowSize = grid.size(), colSize = grid[0].size();
    if(row<0 or col<0 or row>=rowSize or col>=colSize or grid[row][col] == 0) return 0;
    
    grid[row][col] = 0;
    
    return 1 +
      maxArea(grid, row+1, col) +
      maxArea(grid, row-1, col) +
      maxArea(grid, row, col+1) +
      maxArea(grid, row, col-1);
  }
  
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maximumArea = 0;
    
    int rowSize = grid.size(), colSize = grid[0].size();
    for(int i=0; i<rowSize; i++) {
      for(int j=0; j<colSize; j++) {
        if(grid[i][j] == 1) {
          maximumArea = max(maximumArea, maxArea(grid, i, j));
        }
      }
    }
    
    return maximumArea;
  }
};