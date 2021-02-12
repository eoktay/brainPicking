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
  
    bool isLeaf(TreeNode* node)
    {
      return node->left == NULL && node->right == NULL;
    }
  
    bool dfs(TreeNode* node, int currentSum, int target)
    {
      if (node == NULL)
      {
        return false;
      }
      
      if (isLeaf(node))
      {
        // cout << "comparing: " <<  currentSum + node->val << " and " << target << endl;
        return currentSum + node->val == target;
      }
        
      bool left = dfs(node->left, currentSum + node->val, target);
      bool right = dfs(node->right, currentSum + node->val, target);
      
      return left || right;
    }
  
    bool hasPathSum(TreeNode* root, int targetSum) {
      
      if (root == NULL)
        return false;
      
      return dfs(root, 0, targetSum);
      
    }
};
