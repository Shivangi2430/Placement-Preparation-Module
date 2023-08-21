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
    bool isBalanced(TreeNode* root){
        return Balanced(root) != -1;
    }
    int Balanced(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = Balanced(root->left);
        int rh = Balanced(root->right);
        
        if(lh == -1 || rh == -1)
            return -1;
        if(abs(rh - lh) > 1)
            return -1;
        
        return 1 + max(lh, rh);
    }
};