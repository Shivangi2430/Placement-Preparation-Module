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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        
        if(root == NULL)
            return result;
        
        queue<TreeNode*>que;
        
        que.push(root);
        
        bool leftToright = true;  //if true then L to R else R to L
        
        while(!que.empty())
        {
            int size = que.size();
            vector<int>level(size);
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                
                if(leftToright == true)
                {
                    int index = i;
                    level[index] = node->val;
                }
                else
                {
                    int index = size - 1 - i;
                    level[index] = node->val;
                }
                 
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            
            leftToright = !leftToright;
            result.push_back(level);
        }
        return result;
   
     /*   vector<vector<int>>result;
        if(root == NULL) 
            return result;
        queue<TreeNode*>que;
        que.push(root);
        bool lefttoright = true;
        
        while(!que.empty()){
            int size = que.size();
            vector<int>row(size);
            
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                
                int index = lefttoright ? i : size - i - 1;
                    row[index] = node->val;
                
                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
            }
                lefttoright = !lefttoright;
                result.push_back(row);
        }
        return result;  */
    }
};