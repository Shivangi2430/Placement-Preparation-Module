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
    int maxPathSum(TreeNode* root) {
        int maxii = INT_MIN;
        maximumPathsum(root,maxii);
        return maxii;
    }

public:
     int maximumPathsum(TreeNode* node, int &maxii)
     {
     {
         if(node==NULL)return 0;
     }
     int leftSum = max(0, maximumPathsum(node->left,maxii));
     int rightSum = max(0,maximumPathsum(node->right,maxii));

     maxii = max(maxii, leftSum + rightSum + node->val);
     return node->val + max(leftSum,rightSum);
     }
};