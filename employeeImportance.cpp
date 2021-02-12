/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
  
    int getImportance(Employee* current, map<int, Employee*> & sortedEmployees)
    {
      int count = current->importance;
      
      vector<int> subs = current->subordinates;
      for (int i = 0; i < subs.size(); i++)
      {
        count += getImportance(sortedEmployees[subs[i]], sortedEmployees);
      }
      
      return count;
    }
  
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> sortedEmployees;
      
        for (int i = 0; i < employees.size(); i++)
        {
          sortedEmployees[employees[i]->id] = employees[i];
        }
      
        return getImportance(sortedEmployees[id], sortedEmployees);
    }
};
