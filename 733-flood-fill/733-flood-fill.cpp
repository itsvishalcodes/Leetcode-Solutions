class Solution {
public:
  void dfs(vector<vector<int>>& image, int sr, int sc, int& newColor, int color, vector<vector<bool>>& visited) {
    int rowSize = image.size(), colSize = image[0].size();
    if(sr<0 or sr>=rowSize or sc<0 or sc>=colSize or visited[sr][sc] or image[sr][sc]!=color) {
      cout<<"Returning from sr and sc being - "<<sr<<" and "<<sc<<endl;
      return;
    }
    
    cout<<"Changing color at sr and sc being - "<<sr<<" and "<<sc<<endl;
    image[sr][sc] = newColor;
    visited[sr][sc] = true;
    
    dfs(image, sr+1, sc, newColor, color, visited);
    dfs(image, sr-1, sc, newColor, color, visited);
    dfs(image, sr, sc+1, newColor, color, visited);
    dfs(image, sr, sc-1, newColor, color, visited);
  }
  
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
    dfs(image, sr, sc, newColor, image[sr][sc], visited);
    
    return image;
  }
};