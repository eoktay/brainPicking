class Solution {
public:
  
    bool inBounds(vector<int>& arr, int a)
    {
      if (a < 0 || a >= arr.size())
        return false;
      return true;
    }
  
    bool isVisited(unordered_set<int>& visited, int a)
    {
      return visited.find(a) != visited.end();
    }
      
  
    bool canReach(vector<int>& arr, int start) {
      unordered_set<int> visited;
      queue<int> poss;
      poss.push(start);
      int current = start;
      
      while(!poss.empty())
      {
        current = poss.front();
        if (arr[current] == 0)
          return true;
        visited.insert(current);
        int a = current + arr[current];
        int b = current - arr[current];
        if (inBounds(arr, a) && !isVisited(visited, a))
          poss.push(a);
        if (inBounds(arr, b) && !isVisited(visited, b))
          poss.push(b);
        poss.pop();
      }
      
      return false;
    }
};
