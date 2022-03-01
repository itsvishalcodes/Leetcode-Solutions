class Solution {
public:
  bool isCorrectPlaced(vector<vector<char>>& board, char& n, int i, int j) {
    int itI = i, itJ = j;
    
    // Checking the column
    for(itI = i+1; itI < 9; itI++) 
      if(board[itI][j]!='.' and board[itI][j] == n) 
        return false;
    
    // Checking the row
    for(itJ = j+1; itJ < 9; itJ++) 
      if(board[i][itJ] != '.' and board[i][itJ] == n) 
        return false;
    
    // Checking subBox (3x3)
    int subBoxI = (i/3)*3, subBoxJ = (j/3)*3;
    for(itI = subBoxI; itI < subBoxI+3; itI++)
      for(itJ = subBoxJ; itJ < subBoxJ+3; itJ++) 
        if(board[itI][itJ] != '.' and itI!=i and itJ!=j and board[itI][itJ]==n)
          return false;          
    
    return true;
  }
  
  bool isValidSudoku(vector<vector<char>>& board) {
    
    for(int i=0; i<board.size(); i++) {
      for(int j=0; j<board[0].size(); j++) {
        if(board[i][j] != '.') {
          if(!isCorrectPlaced(board, board[i][j], i, j)) {
            return false;
          }
        }
      }
    }
    
    return true;
  }
};