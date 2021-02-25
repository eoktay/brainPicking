class Solution {
public:
  
  
    struct hasher {
      template <class T>
      size_t operator()(const vector<T> & p) const {
        auto hash1 = hash<T>{}(p[0]);
        auto hash2 = hash<T>{}(p[1]);
        
        return hash1 ^ hash2;
      }
    };
  
    struct hasher_vector {
      template <class T>
      size_t operator()(const vector<T> & p) const {
        auto hash1 = hash<T>{}(p[0]);
        auto hash2 = hash<T>{}(p[1]);
        
        return hash1 ^ hash2;
      }
    };
  
    void insertAdj(unordered_map<vector<int>, vector<int>, hasher_vector>& adj, vector<vector<int>>& edges, int color) {
      for (int i = 0; i < edges.size(); i++) {
        adj[{edges[i][0], color}].push_back(edges[i][1]);
      }
    }
  
    void startQueue(unordered_map<vector<int>, vector<int>, hasher_vector>& adj, queue<vector<int>>& starter_queue, 
      unordered_set<vector<int>, hasher> & starter_visited, int color) {
        // cout << "call with color " << color << endl;
        if (adj.find({0, color}) != adj.end()) {
          vector<int> starter = adj[{0, color}];
          for (int j : starter) {
             // first jump counts as one as well
            starter_queue.push({j, color, 1});
            starter_visited.insert({j, color});
          }
        }
        // cout << "end call with color " << color << endl;
    }
  
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
      
      unordered_map<vector<int>, vector<int>, hasher_vector> adj;
      insertAdj(adj, red_edges, 0);
      insertAdj(adj, blue_edges, 1);
      vector<int> ret (n, -1);
      ret[0] = 0; // based on the question..
      queue<vector<int>> starter_queue;
      unordered_set<vector<int>, hasher> starter_visited;
      // 0 is red, 1 is blue
      startQueue(adj, starter_queue, starter_visited, 0);
      startQueue(adj, starter_queue, starter_visited, 1);

      
      for (int i = 1; i < n; i++) {
        queue<vector<int>> queue = starter_queue;
        unordered_set<vector<int>, hasher> visited = starter_visited;

        while(!queue.empty()) {
          vector<int> top = queue.front();
          queue.pop();
          
          if (top[0] == i) {
            ret[i] = top[2];
            break;
          }
          
          int new_color = 1 - top[1];
          if (adj.find({top[0], new_color}) != adj.end()) {
            vector<int> next = adj[{top[0], new_color}];
            for (int j : next) {
              if (visited.find({j, new_color}) == visited.end()) {
                queue.push({j, new_color, top[2] + 1});
                visited.insert({j, new_color});
              }
            }
          }
          
        }
      }
      
      return ret;
      
    }
};
