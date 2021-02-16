class Solution {
public:
  
    bool inBounds(int row, int col, vector<vector<char>>& board)
    {
      if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        return false;
      return true;
    }
  
    void discover(vector<vector<char>>& board, 
      vector<vector<char>>& ret, int row, int col, vector<vector<int>> & dirs)
    {
      if (ret[row][col] != 'O')
      {
        if (board[row][col] == 'O')
        {
          ret[row][col] = 'O';
          for (int i = 0; i < dirs.size(); i++)
          {
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            if (inBounds(newRow, newCol, board))
              discover(board, ret, newRow, newCol, dirs);
          }  
        }
      }
    }
  
    void solve(vector<vector<char>>& board) {
      
        if (board.size() == 0)
          return;
      
        vector<vector<char>> ret (board.size(), 
          vector<char> (board[0].size(), 'X')); 
      
        vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      
        for (int i = 0; i < board[0].size(); i++)
        {
          discover(board, ret, 0, i, dirs);
          discover(board, ret, board.size() - 1, i, dirs);
        }
      
        for (int i = 0; i < board.size(); i++)
        {
          discover(board, ret, i, 0, dirs);
          discover(board, ret, i, board[0].size() - 1, dirs);
        }
      
        board = ret;

    }
};
