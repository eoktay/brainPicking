class Solution {
public:
  
    bool inBounds(vector<vector<int>>& grid, int row, int col) {
      if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
        return false;
      return true;
    }
  
    int orangesRotting(vector<vector<int>>& grid) {
      int ret = 0;
      vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
          if (grid[i][j] == 2) {
            pq.push({0, i, j});
          }
        }
      }  
      
      while(!pq.empty()) {
        vector<int> top = pq.top();
        pq.pop();
        
        for (vector<int> dir : dirs) {
          int newRow = top[1] + dir[0];
          int newCol = top[2] + dir[1];
          if (inBounds(grid, newRow, newCol) && 
            grid[newRow][newCol] == 1) {
            grid[newRow][newCol] = 2;
            int newDays = top[0] + 1;
            pq.push({newDays, newRow, newCol});
            ret = max(ret, newDays);
          }
        }
      }
      
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
          if (grid[i][j] == 1) {
            return -1;
          }
        }
      }
      
      return ret;
      
    }
};
