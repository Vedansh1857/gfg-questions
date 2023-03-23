/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool solveRec(Node* p, Node* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        bool ans =  (p->data == q->data) && (solveRec(p->left,q->left) && solveRec(p->right,q->right));
        return ans;
    }
    bool isIdentical(Node *r1, Node *r2){
        //Your Code here
        return solveRec(r1,r2);
    }
};
