/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
    int countGrandParents(int parent, int gParent, TreeNode* current)
    {
      if (current == NULL)
        return 0;
      
      int count = 0;
      
      if (gParent % 2 == 0)
        count += current->val;
      
      count += countGrandParents(current->val, parent, current->left) + 
        countGrandParents(current->val, parent, current->right);
      
      return count;
      
    }
  
    int sumEvenGrandparent(TreeNode* root) {
      
      return countGrandParents(1, 1, root);
        
    }
};
