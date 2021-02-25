class Solution {
public:
  
  
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> incoming(numCourses, 0);
      
        vector<int> ret;
        for (int i = 0; i < prerequisites.size(); i++)
          incoming[prerequisites[i][0]]++;
        
        int classes = 0;
        queue<int> queue;
        for (int i = 0; i < incoming.size(); i++)
          if (incoming[i] == 0) {
            queue.push(i);
          }
      
        if (queue.size() == 0)
          return false;
      
        unordered_map<int, vector<int>> coursesAdj;
      
        for (int i = 0; i < prerequisites.size(); i++)
          coursesAdj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    
      
        // cout << "queue size: " << queue.size() << endl;
        while(!queue.empty()) {
          int current = queue.front();
          for (int & edge : coursesAdj[current]) {
            incoming[edge]--;
            if (incoming[edge] == 0) {
              queue.push(edge);
            }
          }
          // cout << "queue front: " << queue.front() << endl;
          queue.pop();
          classes++;
          // cout << "classes: " << classes << endl;
        }
        return classes == numCourses;
    }
};
