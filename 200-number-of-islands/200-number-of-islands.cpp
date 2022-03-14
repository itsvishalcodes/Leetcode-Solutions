class Solution {
public:
  
  void dfs(vector<vector<char>>& grid, int rowPos, int colPos, int& rowSize, int& colSize) {
    int i = rowPos, j=colPos;
    
    if(i<0 or j<0 or i>=rowSize or j>=colSize or grid[i][j]=='0') 
      return;
    
    grid[i][j] = '0';
    
    dfs(grid, i+1, j, rowSize, colSize);
    dfs(grid, i-1, j, rowSize, colSize);
    dfs(grid, i, j+1, rowSize, colSize);
    dfs(grid, i, j-1, rowSize, colSize);
    
    return;
  }
  
  int numIslands(vector<vector<char>>& grid) {
    int islands=0;
    int rowSize = grid.size(), colSize = grid[0].size();
    
    for(int i=0; i<rowSize; i++) {
      for(int j=0; j<colSize; j++) {
        if( grid[i][j] == '1' ) {
          islands++;
          dfs(grid, i, j, rowSize, colSize);
        }
      }
    }
    
    return islands;
  }
};