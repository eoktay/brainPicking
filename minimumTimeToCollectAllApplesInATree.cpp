class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        unordered_set<int> visited;
        unordered_set<int> path;
        int ret = 0;
      
        visited.insert(0);
        
      
        queue<pair<int, vector<int>>> queue;
        queue.push({0, {0}});
      
      
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
    
        while(!queue.empty()) {
            pair<int, vector<int>> top = queue.front();
            queue.pop();
            for (int i : adj[top.first]) {
              if (visited.find(i) == visited.end()) {
                vector<int> nextPath = top.second;
                nextPath.push_back(i);
                if (hasApple[i]) {
                  for (int k : nextPath) {
                    path.insert(k);
                  }
                }
                queue.push({i, nextPath});
                visited.insert(i);
              }
            }
          }
         
        ret = 2 * (path.size() - 1);
        return ret > 0 ? ret : 0;
    }
};
