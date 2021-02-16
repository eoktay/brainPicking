/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void zigzagTrav(vector <vector <int> > & ret, TreeNode* root, int level, string dir)
    {
      if (root == NULL)
      {
        return;
      }
      else
      {
        if (ret.size() < level)
        {
          vector<int> temp;
          ret.push_back(temp);
        }
        
        ret[level - 1].push_back(root->val);
        
        if (dir == "left")
        {
          zigzagTrav(ret, root->left, level + 1, "left");
          zigzagTrav(ret, root->right, level + 1, "left");

        }
        else if(dir == "right")
        {   
          zigzagTrav(ret, root->right, level + 1, "right");
          zigzagTrav(ret, root->left, level + 1, "right");
        }
      }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int> > leftRet;
        vector <vector <int> > rightRet;
        vector <vector <int> > ret;
        // cout << root->val << endl;
        zigzagTrav(leftRet, root, 1, "left");
        zigzagTrav(rightRet, root, 1, "right");
      
        int index = 0;
        bool left = true;
      
        while(index < leftRet.size() || index < rightRet.size())
        {
          if (index < leftRet.size() && left)
          {
            if (leftRet[index].size() != 0)
            ret.push_back(leftRet[index]);
          }
          if (index < rightRet.size() && !left)
          {
            if (rightRet[index].size() != 0)
            ret.push_back(rightRet[index]);
          }
          left = !left;
          index++;
        }
          
        return ret;
    }
};

//             1
//         2         3
//     4     5     6     7
//    8 9  10 11 12 13 14 15       
          
          
