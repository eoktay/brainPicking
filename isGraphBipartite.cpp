class Solution {
public:
  
    bool check(vector<unordered_set<int>> & bags, vector<vector<int>>& graph, 
      int bag, int node, unordered_set<int> & visited)
    {
      visited.insert(node);
      bool ret = true;
      
      if (bags[1 - bag].find(node) != bags[1 - bag].end())
      {
        return false;
      }
      
      if (bags[bag].find(node) != bags[bag].end())
        return true;
      bags[bag].insert(node);
      
      for (int i = 0; i < graph[node].size(); i++)
        ret &= check(bags, graph, 1 - bag, graph[node][i], visited);
      
      return ret;
      
    }
  
    bool isBipartite(vector<vector<int>>& graph) {

        vector<unordered_set<int>> bags (2, unordered_set<int>());
        // bags[0].insert(1);
        // cout << "bag 0 first val exists: " << (bags[0].find(1) != bags[0].end()) << endl;
        unordered_set<int> visited;
  
        bool ret = true;
        for (int i = 0; i < graph.size(); i++)  
          if (visited.find(i) == visited.end())
            ret &= check(bags, graph, 0, i, visited);
      
        return ret;
    }
};
