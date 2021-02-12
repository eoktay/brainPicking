class Solution {
public:
  
    bool inBounds(vector<vector<char>>& board, int row, int column)
    {
      if (row < 0 || row >= board.size() 
         || column < 0 || column >= board[0].size())
        return false;
      
      return true;
    }
  
    void goTo(vector<vector<char>>& board, vector<int>& click, vector<pair<int, int>> & dirs)
    { 
      // cout << "loop" << endl;
      // cout << "row: " << click[0] << endl;
      // cout << "column: " << click[1] << endl;
      if (board[click[0]][click[1]] == 'M')
      {
        board[click[0]][click[1]] = 'X';
        return;
      }
      else if (board[click[0]][click[1]] == 'E')
      {
        for (int i = 0; i < dirs.size(); i++)
        {
          int row = click[0] + dirs[i].first;
          int column = click[1] + dirs[i].second;
          
          if (inBounds(board, row, column))
          {
            if (board[row][column] == 'M')
            {
              if (board[click[0]][click[1]] >= '0' && board[click[0]][click[1]] <= '7')
              {
                board[click[0]][click[1]] += 1; 
              }
              else
                board[click[0]][click[1]] = '1';
            }
          }
        }
        if (board[click[0]][click[1]] >= '0' && board[click[0]][click[1]] <= '8')
          return;
        board[click[0]][click[1]] = 'B';
        for (int i = 0; i < dirs.size(); i++)
        {
          int row = click[0] + dirs[i].first;
          int column = click[1] + dirs[i].second;
          if (inBounds(board, row, column))
          {
            vector<int> nextClick;
            nextClick.push_back(row);
            nextClick.push_back(column);
            goTo(board, nextClick, dirs);
          }
        }
      }
      return;
    }
  
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      
      vector<pair<int, int>> dirs;
      
      dirs.push_back(make_pair(1, 0));
      dirs.push_back(make_pair(-1, 0));
      dirs.push_back(make_pair(0, 1));
      dirs.push_back(make_pair(0, -1));
      dirs.push_back(make_pair(1, 1));
      dirs.push_back(make_pair(1, -1));
      dirs.push_back(make_pair(-1, -1));
      dirs.push_back(make_pair(-1, 1));
      
      
      if (!inBounds(board, click[0], click[1]))
        return board;
      
      goTo(board, click, dirs);
      
      return board;

    }
};
