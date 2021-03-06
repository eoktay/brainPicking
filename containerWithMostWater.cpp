class Solution {
public:
    int maxArea(vector<int>& height) {
      int index1 = 0;
      int index2 = height.size() - 1;
      int area = 0;
      
      while(index1 != index2) {
        area = max(area, (index2 - index1) * min(height[index1], height[index2]));
        if ((height[index2] > height[index1])) {
          index1++;
        }
        else if ((height[index1] > height[index2])){
          index2--;
        }
        else if (height[index1] == height[index2]) {
          if (index1 - index2 == 1) {
            index1++;
          }
          else if (height[index1 + 1] > height[index2 - 1]) {
            index1++;
          }
          else {
            index2--;
          }
        }
      }
      return area;
    }
};
