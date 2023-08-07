//for min heap parentnode < left && parentnode <right
//BST left < right
//inorder is always in sorted order
//preorder follows rule node-left-right
//hence inorder will give all in sorted manner and preorder of inorder will give the min heap 


void inorder(BinaryTreeNode* root, vector<int> &ans)
{
	// base case
	if(root==NULL)
	{
		return;
	}

	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);
}

void preorderFill(BinaryTreeNode* root, int &index, vector<int> &ans)
{
	if(root==NULL)
	{
		return;
	}

	root->data=ans[index++];
	preorderFill(root->left, index, ans);
	preorderFill(root->right, index, ans);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> ans;
	inorder(root, ans);

	int index=0;
	preorderFill(root, index, ans);

	return root;
}
