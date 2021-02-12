class Solution {
public:
  
  
    void dfs(int index, vector<vector<int>>& isConnected, map<int, bool> & covered)
    {
      if (covered[index])
        return;
      
      covered[index] = true;
      
      for (int i = 0; i < isConnected[index].size(); i++)
      {
        if (isConnected[index][i])
          dfs(i, isConnected, covered);
      }
      
      return;
    }
  
    int findCircleNum(vector<vector<int>>& isConnected) {
       map<int, bool> covered;
      
        int count = 0;
      
       for (int i = 0; i < isConnected.size(); i++)
       {
         covered[i] = false;
       }
      
       for (map<int, bool>::iterator it = covered.begin(); it != covered.end(); it++)
       {
         if (it->second == false)
         {
           count++;
           dfs(it->first, isConnected, covered);
         }
       }
      
      return count;
       
    }
};
