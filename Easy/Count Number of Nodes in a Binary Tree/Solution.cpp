// User function Template for C++

class Solution {
  public:
  void inorder(Node* root,int &c){
    if(root==NULL){
        return;
    }
    inorder(root->left,c);
    c++;
    inorder(root->right,c);
}
    int countNodes(Node* root){
        // Write your code here
        int c=0;
        inorder(root,c);
        return c;
    }
};
