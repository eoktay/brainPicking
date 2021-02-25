class Solution {
public:
  
    void dfs(int i, unordered_set<int> & visited, unordered_map<int, vector<int>> & adj, 
      vector<int> & ret, bool & cycle)
    {
      if (visited.find(i) != visited.end())
      {
        if (find(ret.begin(), ret.end(), i) == ret.end())
          cycle = true;
        return;
      }
      visited.insert(i);
      if (adj.find(i) == adj.end()) {
        ret.push_back(i);
        return;
      }
      for (int j : adj[i]) {
        dfs(j, visited, adj, ret, cycle);
      }
      ret.push_back(i);
    }
  
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        vector<int> ret;
        bool cycle = false;
        for (int i = 0; i < prerequisites.size(); i++) {
          adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
      
        for (int i = 0; i < numCourses; i++) {
          if (visited.find(i) == visited.end())
            dfs(i, visited, adj, ret, cycle);
        }
      
        // reverse(ret.begin(), ret.end());
        if (cycle)
          return {};
        return ret;
    }
};
