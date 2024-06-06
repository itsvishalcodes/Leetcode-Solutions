class Solution {
public:
  void fill(vector<vector<int>>& image, int sr, int sc, int *color, int *currColor, set<pair<int, int>>& visited) {
    if(sr<0 || sr>=image.size() || 
      sc<0 || sc>=image[0].size() || 
      visited.find(make_pair(sr, sc))!=visited.end() ||
      image[sr][sc] != *currColor
    ) {
      return;
    }

    visited.insert(make_pair(sr, sc));
    image[sr][sc] = *color;
    fill(image, sr-1, sc, color, currColor, visited);
    fill(image, sr, sc-1, color, currColor, visited);
    fill(image, sr+1, sc, color, currColor, visited);
    fill(image, sr, sc+1, color, currColor, visited);
    return;
  }
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int currColor = image[sr][sc];
    set<pair<int, int>> visited;
    fill(image, sr, sc, &color, &currColor, visited);
    return image;
  }
};