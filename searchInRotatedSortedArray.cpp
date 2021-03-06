class Solution {
public:
    
    void findRotation(int left, int right, vector<int>& nums, int & breakPoint) {
      if (breakPoint != -1) {
        return;
      }
      if (left == right) {
        if (left != 0 && nums[left - 1] > nums[left]) {
          breakPoint = left;
        }
        return;
      }
      int mid = (left + right) / 2;

      if (left != 0 && nums[left - 1] > nums[left]) {
        breakPoint = left;
        return;
      }
      else if (nums[mid] > nums[right]) {
        findRotation(mid + 1, right, nums, breakPoint);
      }
      else if (nums[mid] < nums[left]) {
        findRotation(left, mid, nums, breakPoint);
      }
      
      if (nums[mid] == nums[right]) {
        findRotation(mid + 1, right, nums, breakPoint);
      }
      
      if (nums[mid] == nums[left]) {
        findRotation(left, mid, nums, breakPoint);
      }
    }
  
  
    bool search(vector<int>& nums, int target) {
      int size = nums.size();
      
      if (size == 1) {
        return nums[0] == target;
      }
      
      int breakPoint = -1;
      findRotation(0, size - 1, nums, breakPoint);
      if (breakPoint == -1) {
        return binary_search(nums.begin(), nums.end(), target);
      }
      
      return binary_search(nums.begin(), nums.begin() + breakPoint, target) || 
        binary_search(nums.begin() + breakPoint, nums.end(), target);
    }
};
