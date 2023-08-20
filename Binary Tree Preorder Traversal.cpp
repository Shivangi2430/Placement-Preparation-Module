class Solution {
public:
    void solve(TreeNode* root, vector<int>&preorder){
        if(root == NULL)
            return;
        
        preorder.push_back(root->val);
        solve(root->left, preorder);
        solve(root->right, preorder);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        solve(root, preorder);
        return preorder;
    }
};
