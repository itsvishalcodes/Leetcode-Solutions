class Solution {
public:
  void dfs(vector<vector<int>>& grid, int r, int c) {
    if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c] == 0) return;
    
    grid[r][c] = 0;
    
    dfs(grid, r+1, c); dfs(grid, r-1, c); dfs(grid, r, c+1); dfs(grid, r, c-1);
  }
  
  int numEnclaves(vector<vector<int>>& grid) {
    for(int i=0; i<grid[0].size(); i++) {
      if(grid[0][i] == 1) dfs(grid, 0, i);
    }
    for(int i=0; i<grid[grid.size()-1].size(); i++) {
      if(grid[grid.size()-1][i] == 1) dfs(grid, grid.size()-1, i);
    }
    for(int i=0; i<grid.size(); i++) {
      if(grid[i][0] == 1) dfs(grid, i, 0);
    }
    for(int i=0; i<grid.size(); i++) {
      if(grid[i][grid[0].size()-1] == 1) dfs(grid, i, grid[0].size()-1);
    }
    
    int soln = 0;
    
    for(int i=0; i<grid.size(); i++) {
      for(int j=0; j<grid[0].size(); j++) {
        if(grid[i][j] == 1) soln++;
      }
    }
    
    return soln;
  }
};