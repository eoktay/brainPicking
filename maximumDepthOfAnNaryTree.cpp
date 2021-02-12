/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  
  
public:
    bool isLeaf(Node* node)
    {
      return node->children.size() == 0;
    }
  
    int maxDepth(Node* root) {
        int level = 0;
        int maxLevel = 0;
      
        if (root == NULL)
          return 0;
        queue<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {       
          int size = nodes.size();
          for (int i = 0; i < size; i++)
          {
            if (isLeaf(nodes.front()))
            {
              // cout << nodes.front()->val << endl;
              maxLevel = max(maxLevel, level + 1);
            }
            for (int j = 0; j < nodes.front()->children.size(); j++)
            {
              if (nodes.front()->children[j] != NULL)
                nodes.push(nodes.front()->children[j]);
            }

            nodes.pop();
          }
          level++;
        }
        return maxLevel;
    }
};
