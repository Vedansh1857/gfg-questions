/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root, vector<int>& ans){
        if(root==NULL) return;
        inorder(root -> left,ans);
        ans.push_back(root -> data);
        inorder(root -> right,ans);
    }
    vector<int> merge(Node *root1, Node *root2){
        //Your code here
        vector<int> list1;
        inorder(root1,list1);
        vector<int> list2;
        inorder(root2,list2);
        vector<int> list3;
        int i=0,j=0;
        while(i<list1.size() && j<list2.size()){
            if(list1[i] < list2[j]){
                list3.push_back(list1[i]);
                i++;
            }
            else{
                list3.push_back(list2[j]);
                j++;
            }
        }
        while(i<list1.size()) list3.push_back(list1[i++]);
        while(j<list2.size()) list3.push_back(list2[j++]);

        return list3;
    }
};
