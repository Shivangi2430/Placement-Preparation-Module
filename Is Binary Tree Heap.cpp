class Solution {
  public:
  int Nodecount(struct Node* root){
      if( root == NULL ){
          return 0;
      }
      else{
          int ans = 1 + Nodecount(root->left) + Nodecount(root->right);
          return ans;
      }
  }
  int CBT(Node* root , int index , int totalcount){
     if(root == NULL){
         return true;
     } 
     if( index >= totalcount){
         return false;
     }
     else{
         int left = CBT(root->left,2*index+1,totalcount);
         int right = CBT(root->right,2*index+2,totalcount);
         return (left && right);
     }
  }
  int maxheap(Node* root){
      if(root == NULL){
         return true;
     } 
     
      if(root->left==NULL && root->right==NULL){
          return true;
      }
      if(root->right == NULL){
          return (root->data > root->left->data) ;
      }
      else{
          bool left = maxheap(root->left);
          bool right = maxheap(root->right);
        return ( left && right && 
        (root->data > root->left->data && 
          root->data > root->right->data ));
      }
  }
    bool isHeap(struct Node* tree) {
        //tree is given as the root
        int index = 0;
        int totalcount = Nodecount(tree);
       if(CBT(tree , index , totalcount ) && maxheap(tree)){
           return true;
       }
       else{
           return false;
       }
    }
};
