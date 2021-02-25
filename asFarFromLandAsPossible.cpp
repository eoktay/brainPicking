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
  
    int maxDistance(vector<vector<int>>& grid) {
        bool landSeen = false;
        bool waterSeen = false;
        int ret = 0;
        vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> dist (grid.size(), vector<int>(grid[0].size(), 0));
        unordered_set<vector<int>, hasher_set> visited;
        queue<vector<int>> queue;
      
        for (int i = 0; i < grid.size(); i++) {
          for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
              queue.push({i, j, 0});
              landSeen = true;
            }
            else if (grid[i][j] == 0) {
              waterSeen = true;
            }
          }
        }
      
        if (!waterSeen || !landSeen) 
          return -1;
      
        while(!queue.empty()) {
          vector<int> top = queue.front();
          queue.pop();
          dist[top[0]][top[1]] = top[2];
          ret = max(ret, dist[top[0]][top[1]]);
          
          for (vector<int> dir : dirs) {
            int newRow = top[0] + dir[0];
            int newCol = top[1] + dir[1];
            
            if (inBounds(grid, newRow, newCol) && visited.find({newRow, newCol}) == visited.end() && grid[newRow][newCol] == 0) {
              visited.insert({newRow, newCol});
              queue.push({newRow, newCol, top[2] + 1});
            }
          }
          
        }
      
        return ret;
    }
};
