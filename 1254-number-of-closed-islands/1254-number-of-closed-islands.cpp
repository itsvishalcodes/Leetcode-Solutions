class Solution {
public:
  // Returns True if you can exit the matrix
  bool canGoOut(vector<vector<int>>& grid, int row, int col) {
    // Base Case
    // 1. If you could go out of matrix
    if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size()) return true;
    // 2. If you encountered water
    if(grid[row][col] == 1) return false;
    
    // Recursive Case
    grid[row][col] = 1;
    
    bool b1 = canGoOut(grid, row+1, col);
    bool b2 = canGoOut(grid, row-1, col);
    bool b3 = canGoOut(grid, row, col+1);
    bool b4 = canGoOut(grid, row, col-1);
    
    if(b1 or b2 or b3 or b4) return true;
    return false;
  }
  
  int closedIsland(vector<vector<int>>& grid) {
    int totalClosedIslands = 0;
    
    for(int i=0; i<grid.size(); i++) {
      for(int j=0; j<grid[0].size(); j++) {
        if(grid[i][j]==0 and !canGoOut(grid, i, j)) {
          totalClosedIslands++;
        }
      }
    }
    
    return totalClosedIslands;
  }
};