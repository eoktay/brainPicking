/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */



class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
      
      vector<vector<int>> ret;
      
      for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++) {
          int start = j;
          int end = 1000;
          int mid;
          bool equal = false;
          int curRes;
          while(start <= end && !equal) {
            mid = start + (end - start) / 2;
            // CustomFunction* function = new CustomFunction(z);
            curRes = customfunction.f(i, mid);
            equal = curRes == z;
            if (curRes > z) {
              end = mid - 1;
            }
            else if (curRes < z)
              start = mid + 1;
          }
          if(equal){
            ret.push_back({i, mid});
            j = mid;
          }
        }
      
        return ret;
    }
};
