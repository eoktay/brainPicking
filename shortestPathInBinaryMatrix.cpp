class Solution {
public:
  
      struct hasher_set {
      template <class T>
      size_t operator()(const vector<T> & p) const {
        auto hash1 = hash<T>{}(p[0]);
        auto hash2 = hash<T>{}(p[1]);
        
        return hash1 ^ hash2;
      }
    };
  
      bool inBounds(vector<vector<int>>& grid, int row, int col) {
      if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
        return false;
      return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
      vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};
      unordered_set<vector<int>, hasher_set> visited;
      if (grid[0][0] != 0)
        return -1;
      
      queue<vector<int>> queue;
      queue.push({0, 0, 1});
      visited.insert({0, 0});
      
      while(!queue.empty()) {
        vector<int> top = queue.front();
        queue.pop();
        
        if (top[0] == grid.size() - 1 && top[1] == grid[0].size() - 1) {
          return top[2];
        }
        
        for (vector<int> dir : dirs) {
          int newRow = top[0] + dir[0];
          int newCol = top[1] + dir[1];
          if (inBounds(grid, newRow, newCol) && visited.find({newRow, newCol}) == visited.end() && grid[newRow][newCol] == 0) {
            visited.insert({newRow, newCol});
            queue.push({newRow, newCol, top[2] + 1});
          }
        }
        
      }
      
      return -1;
        
    }
};
