class Solution {
public:
  int soln = 0;
  
  bool canPlace(vector<string>& board, int n, int i, int j) {
    // check column
    for(int it=i; it>=0; it--) {
      if(board[it][j]=='Q') return false;
    }
    
    // chech for left diagonal
    int tempI = i, tempJ = j;
    while(tempI>=0 and tempJ>=0) {
      if(board[tempI][tempJ]=='Q') return false;
      tempI--; tempJ--;
    }
    
    // check for right diagonal
    tempI = i, tempJ = j;
    while(tempI>=0 and tempJ < n) {
      if(board[tempI][tempJ]=='Q') return false;
      tempI--; tempJ++;
    }
    
    return true;
  }
  
  void placeQueen(int n, vector<string>& board, int i) {
    // Base Case
    if(i==n) {
      soln++;
      return;
    }
    
    // Recursive Case
    // Check if the current Queen can be placed at curr location for all col of curr row
    for(int j=0; j<n; j++) {
      if(canPlace(board, n, i, j)) {
        // Place the queen
        board[i][j] = 'Q';
        placeQueen(n, board, i+1);
        
        // Backtracking step
        board[i][j] = '.';
      }
    }
    
    return;
  }
  
  int totalNQueens(int n) {
    string s="";
    for(int i=0; i<n; i++) s+=".";
    
    vector<string> board(n, s);
    
    placeQueen(n, board, 0);
    
    return soln;
  }
};