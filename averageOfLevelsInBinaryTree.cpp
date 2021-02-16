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
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode*> level;
      level.push(root);
      vector<double> ret;
      while(!level.empty())
      {
        int size = level.size();
        double total = 0;
        for (int i = 0; i < size; i++)
        {
          total += level.front()->val;
          TreeNode* current = level.front();
          if (current->left != NULL)
            level.push(current->left);
          if (current->right != NULL)
            level.push(current->right);
          level.pop();
        }
        ret.push_back(total / size);
      }
      return ret;
    }
};
