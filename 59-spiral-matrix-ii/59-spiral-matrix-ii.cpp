class Solution {
public:
  bool isInvalid(int R, int C, vector<vector<bool>>& visited) {
    int n = visited.size();
    if(R<0 or C<0 or R>=n or C>=n or visited[R][C]) {
      return true;
    }
    return false;
  }
  
  vector<vector<int>> generateMatrix(int n) {
    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};
    vector<vector<int>> soln(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int state = 0, R=0, C=0;
    
    for(int i=0; i<n*n; i++) {
      soln[R][C] = i+1;
      visited[R][C] = true;
      if(isInvalid(R+dr[state], C+dc[state], visited)) {
        state = (state+1)%4;
      }
      R = R + dr[state];
      C = C + dc[state];
    }
    
    return soln;
  }
};