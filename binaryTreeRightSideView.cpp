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
  
    void goDown(TreeNode* current, vector<int> & seen, 
      unordered_set<int> & levelSeen, int level)
    {
      if (current == NULL)
        return;
      if (levelSeen.find(level) == levelSeen.end())
      {
        seen.push_back(current->val);
        levelSeen.insert(level);
      }
      goDown(current->right, seen, levelSeen, level + 1);
      goDown(current->left, seen, levelSeen, level + 1);
    }
  
    vector<int> rightSideView(TreeNode* root) {
        vector<int> seen;
        unordered_set<int> levelSeen;
          
        goDown(root, seen, levelSeen, 0);
      
        return seen;
    }
};
