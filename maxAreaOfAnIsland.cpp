class Solution {
public:
  
    bool inBounds(int row, int col, vector<vector<int>> & grid)
    {
      if (row < 0 || row >= grid.size() 
          || col < 0 || col >= grid[0].size())
      {
        return false;
      }
      
      return true;
    }
  
  
    int count(vector<vector<int>> grid, vector<vector<int>> & visited, 
      int row, int col, vector<pair<int, int>> & dirs)
    {
//       cout << "row: " << row << endl;
//       cout << "col: " << col << endl;
      
      if (visited[row][col])
        return 0;
        
       if(!grid[row][col])
       {
         visited[row][col] = 1;
          return 0;
       }
      
      int area = 1;
      visited[row][col] = 1;
      
      for (int i = 0; i < dirs.size(); i++)
      {
        int newRow = row + dirs[i].first;
        int newCol = col + dirs[i].second;
        if (inBounds(newRow, newCol, grid))
          area += count(grid, visited, newRow, newCol, dirs);
      }
      return area;
    }
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      
        if (grid.size() == 0)
          return 0;
      
        vector<vector<int>> visited = grid;
        vector<pair<int, int>> dirs;
        dirs.push_back(make_pair(1, 0));
        dirs.push_back(make_pair(0, 1));
        dirs.push_back(make_pair(-1, 0));
        dirs.push_back(make_pair(0, -1));
      
        int ret = 0;
      
        for (int i = 0; i < visited.size(); i++)
        {
          for (int j = 0; j < visited[0].size(); j++)
          {
            visited[i][j] = 0;
          }
        }
      
      
        for (int i = 0; i < visited.size(); i++)
        {
          for (int j = 0; j < visited[0].size(); j++)
          {
            if (!visited[i][j] && grid[i][j])
              ret = max(ret, count(grid, visited, i, j, dirs));
          }
        }
      
        return ret;
    }
};
