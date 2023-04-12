class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K){
        //Your code here
        if(root != NULL){
            if(root->data == K) return 0 ;
            else if(root->data>K) return min(minDiff(root->left,K),abs(root->data-K));
            else return min(minDiff(root->right,K),abs(root->data-K));
        }
        else return INT_MAX;
    }
};
