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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>nodes;  //(verticle, level, node)
        queue<pair<TreeNode*,pair<int,int>>>todo;  //(node, verticle, level)   
        
        todo.push({root,{0,0}});   //pushing the first node value into the queue
        
        while(!todo.empty())  ///while queue is not empty
        {
            auto p = todo.front(); 
            todo.pop();
            TreeNode* node = p.first; //node value 
            int x = p.second.first;   //vertical
            int y = p.second.second;  //level
            nodes[x][y].insert(node->val);

            if(node->left)
               todo.push({node->left,{x-1,y+1}});
            
            if(node->right)
               todo.push({node->right,{x+1,y+1}});
        }

           vector<vector<int>>ans;
           for(auto p : nodes)
           {
               vector<int>col;
               for(auto q : p.second)
               {
                   col.insert(col.end(),q.second.begin(),q.second.end());
               }
             ans.push_back(col);
           
          }
        return ans;
    }
};