Node* solve(vector<int>&arr, int i, int n){
    Node *root = NULL;
    if(i<n){
      root = new Node(arr[i]);
      root->left = solve(arr, 2*i+1, n);
      root->right = solve(arr, 2*i + 2, n);
    }
    return root;
}

Node* createTree(vector<int>&arr){
    // Write your code here.
   return solve(arr, 0, arr.size());

}
