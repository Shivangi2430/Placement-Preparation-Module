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
    
    // TC = O(n)  SC = O(n)
    
    vector<vector<int>> levelOrder(TreeNode* root) {
       
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            vector<int>level;
            
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
                
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
        
       /* vector<vector<int>>answer;
        if(root == NULL)
            return answer;
        
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            vector<int>level;
            
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                
                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
                
                level.push_back(node->val);
            }
            answer.push_back(level);
        }
        return answer;*/
    }
};